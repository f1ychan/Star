/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       shoot_task.c/h
  * @brief      射击功能.
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Dec-26-2018     RM              1. 完成
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#include "shoot_task.h"
#include "chassis_task.h"
#include "main.h"

#include "cmsis_os.h"

#include "bsp_laser.h"
#include "arm_math.h"
#include "user_lib.h"
#include "referee.h"

#include "CAN_receive.h"
#include "gimbal_behaviour.h"
#include "detect_task.h"
#include "pid.h"
#include "tim.h"
#include "stm32.h"
														//开启发弹摩擦轮
#define shoot_fric(speed) 	shoot_control.fric_left_speed_set = -speed;\
														shoot_control.fric_right_speed_set = speed    
#define trigger_motor(speed)				shoot_control.trigger_speed_set = -speed //开启拨弹电机
//行程开关IO
#define BUTTEN_TRIG_PIN     HAL_GPIO_ReadPin(BUTTON_TRIG_GPIO_Port, BUTTON_TRIG_Pin)
#define shoot_laser_on()    laser_on()      //激光开启宏定义
#define shoot_laser_off()   laser_off()     //激光关闭宏定义

static void shoot_init(void);
/**
  * @brief          摩擦轮模式切换
  * @param[in]      void
  * @retval         void
  */
static void shoot_set_mode(void);
/**
  * @brief          电机速度计算
  * @param[in]      void
  * @retval         void
  */
static void shoot_control_loop(void);
/**
  * @brief          射击数据更新
  * @param[in]      void
  * @retval         void
  */
static void shoot_feedback_update(void);
/**
  * @brief          卡弹拨盘回拨
  * @param[in]      void
  * @retval         void
  */
static void trigger_motor_turn_back(void);





shoot_control_t shoot_control;          //射击数据
static int16_t left_can_set_current = 0, right_can_set_current = 0, trigger_can_set_current = 0;
/**
  * @brief          射击任务
  * @param[in]      void
  * @retval         返回can控制值
  */
void shoot_task(void const *pvParameters)
{
		vTaskDelay(SHOOT_TASK_INIT_TIME);
		shoot_init();
		while(1)
		{
				shoot_set_mode();
				shoot_feedback_update();
				shoot_control_loop();		 //设置发弹控制量
			  if (!(toe_is_error(FRIC_LEFT_MOTOR_TOE) && toe_is_error(FRIC_RIGHT_MOTOR_TOE)	&& toe_is_error(TRIGGER_MOTOR_TOE)))
        {
            if (toe_is_error(DBUS_TOE))
            {
                CAN_cmd_shoot(0, 0, 0, 0);
            }
            else
            {
                CAN_cmd_shoot(0 ,left_can_set_current, right_can_set_current, trigger_can_set_current);
            }
        }
				vTaskDelay(SHOOT_CONTROL_TIME_MS);
		}
}

/**
  * @brief          射击初始化，初始化PID，遥控器指针，电机指针
  * @param[in]      void
  * @retval         返回空
  */
void shoot_init(void)
{
		//电机PID初始化
		static const fp32 Trigger_speed_pid[3] = {TRIGGER_ANGLE_PID_KP, TRIGGER_ANGLE_PID_KI, TRIGGER_ANGLE_PID_KD};
    static const fp32 fric_left_pid[3] = {FRIC_LEFT_MOTOR_SPEED_PID_KP, FRIC_LEFT_MOTOR_SPEED_PID_KI, FRIC_LEFT_MOTOR_SPEED_PID_KD};
		static const fp32 fric_right_pid[3] = {FRIC_RIGHT_MOTOR_SPEED_PID_KP, FRIC_RIGHT_MOTOR_SPEED_PID_KI, FRIC_RIGHT_MOTOR_SPEED_PID_KD};
		
    //遥控器指针
    shoot_control.shoot_rc = get_remote_control_point();
    //电机指针
    shoot_control.trigger_motor_measure = get_trigger_motor_measure_point();
		shoot_control.fric_left_motor_measure = get_can_3508_left_measure_point();
		shoot_control.fric_right_motor_measure = get_can_3508_right_measure_point();
    //初始化PID
		PID_init(&shoot_control.trigger_pid, PID_POSITION, Trigger_speed_pid, TRIGGER_READY_PID_MAX_OUT, TRIGGER_READY_PID_MAX_IOUT);		
		PID_init(&shoot_control.fric_left_pid, PID_POSITION, fric_left_pid, FRIC_LEFT_MOTOR_SPEED_PID_MAX_OUT, FRIC_LEFT_MOTOR_SPEED_PID_MAX_IOUT);
		PID_init(&shoot_control.fric_right_pid, PID_POSITION, fric_right_pid, FRIC_RIGHT_MOTOR_SPEED_PID_MAX_OUT, FRIC_RIGHT_MOTOR_SPEED_PID_MAX_IOUT);
    //更新数据
		shoot_control.shoot_flag = 0;
		shoot_control.bullet_flag = 0;
		shoot_control.shoot_continu_flag = 0;
		shoot_control.stuck_flag = 0;
		shoot_control.reverse_time = 0;
		shoot_control.shoot_time = 150;
		
		shoot_control.trigger_given_current = 0;
    shoot_control.trigger_speed = 0.0f;
    shoot_control.trigger_speed_set = 0.0f;
		shoot_control.fric_left_speed = 0.0f;
    shoot_control.fric_left_speed_set = 0.0f;
		shoot_control.fric_right_speed = 0.0f;
    shoot_control.fric_right_speed_set = 0.0f;
		
		shoot_control.trigger_angle = 0;
		shoot_control.trigger_angle_set = shoot_control.trigger_angle;
}
/**
  * @brief          射击状态机设置
  * @param[in]      void
  * @retval         void
  */
int8_t R = 0;
int s=2000,l;
 static void shoot_set_mode(void)
{
		static int8_t press_l_last_s = 0;
		fp32 fric_speed;
		static int16_t last_key_R = 0;
		if(!last_key_R&&shoot_control.shoot_rc->key.v & KEY_PRESSED_OFFSET_R)
		{
				R=!R;
		}
		last_key_R = shoot_control.shoot_rc->key.v & KEY_PRESSED_OFFSET_R;
	#if SHOOT_THIRD_MODE
		
		if ((switch_is_up(shoot_control.shoot_rc->rc.s[1]) || R) && robot_state.mains_power_shooter_output)
    {
				laser_on();
				trigger_motor_turn_back();
				//根据裁判系统 控制弹速
				switch (robot_state.shooter_id1_42mm_speed_limit)
				{
						case 10:
						{
								fric_speed = 4200;
								break;
						}					
						case 16:
						{
								fric_speed = 5900;
								break;
						}
						default:
						{
								fric_speed = 5900;
								break;
						}
				}
				shoot_fric(fric_speed);
				if(shoot_control.stuck_flag == 0)//无卡弹
				{
						//拨弹
						if(!BUTTEN_TRIG_PIN && shoot_control.fric_b_motor_measure->given_current >= 100)  trigger_motor(0.0f);
						else if(BUTTEN_TRIG_PIN)	trigger_motor(4.0f);
					
						if(shoot_control.shoot_rc->rc.ch[4] < 120)
						{
								shoot_control.bullet_flag = 1;
						}
						//发弹
						if(shoot_control.bullet_flag == 1 && (shoot_control.shoot_rc->rc.ch[4] > 600 || (!press_l_last_s && shoot_control.press_l)) &&
							!BUTTEN_TRIG_PIN && (robot_state.shooter_id1_42mm_cooling_limit - power_heat_data_t.shooter_id1_42mm_cooling_heat >= 100))
						{
								shoot_control.shoot_flag = 1;
								shoot_control.bullet_flag = 0;
						}
				}
				else if(shoot_control.stuck_flag == 1)//卡弹
				{
						third_fric(0);	
						trigger_motor(-3.0f);
				}
    }
		else
		{
				laser_off();
				shoot_fric(0);
				third_fric(0);	
				trigger_motor(0.0f);
		}
		
		if(shoot_control.shoot_flag ==1)
		{
				shoot_control.shoot_time = 0;
				shoot_control.shoot_flag = 0;
		}
		//二级拨弹
		if(shoot_control.shoot_time < 50)
		{
				third_fric(15000);
				trigger_motor(8.0f);
		}
		else
		{
				third_fric(0);
		}
		
	#else

		if ((switch_is_up(shoot_control.shoot_rc->rc.s[1]) || R) && robot_state.mains_power_shooter_output)
    {
				laser_on();
				trigger_motor_turn_back();
				//根据裁判系统 控制弹速
			//于丽敏 注释 改摩擦轮转速
				switch (robot_state.shooter_id1_42mm_speed_limit)
				{
						case 10:
						{
								fric_speed = 4000;//10->4000
								break;
						}					
						case 16:
						{
								fric_speed = 6000;//16->5800
								break;
						}
						default:
						{
								fric_speed = 6000;
								break;
						}
				}
				shoot_fric(fric_speed);			
				if(shoot_control.stuck_flag == 0)//无卡弹
				{
						//拨弹
						if(!BUTTEN_TRIG_PIN)  	trigger_motor(0.0f);
					//供弹力度 于丽敏
						else if(BUTTEN_TRIG_PIN)		trigger_motor(7.0f);
					
						if(shoot_control.shoot_rc->rc.ch[4] < 120)
						{
								shoot_control.bullet_flag = 1;
						}
						//发弹
						if(shoot_control.bullet_flag == 1 && (shoot_control.shoot_rc->rc.ch[4] > 600 || (!press_l_last_s && shoot_control.press_l)) &&
							!BUTTEN_TRIG_PIN && (robot_state.shooter_id1_42mm_cooling_limit - power_heat_data_t.shooter_id1_42mm_cooling_heat >= 100)) 
						{
								shoot_control.shoot_flag = 1;
								shoot_control.bullet_flag = 0;
						}
				}
				else if(shoot_control.stuck_flag == 1)//卡弹
				{
						trigger_motor(-5.0f);
				}
    }
		else
		{
				laser_off();
			PID_clear(&shoot_control.trigger_pid);
			PID_clear(&shoot_control.fric_left_pid);
			PID_clear(&shoot_control.fric_right_pid);
				shoot_fric(0);
				trigger_motor(0);
		}
		
		if(shoot_control.shoot_flag ==1 && shoot_control.shoot_time > 60)
		{
				shoot_control.shoot_time = 0;
				shoot_control.shoot_flag = 0;
		}
		//拨弹
		//于丽敏 注释 改拨弹电机力度
		if(shoot_control.shoot_time < 55)//改拨弹时间
		{
				switch (robot_state.shooter_id1_42mm_speed_limit)
				{
						case 10:
						{
								trigger_motor(7.0f);//力度
								break;
						}					
						case 16:
						{
								trigger_motor(10.0f);
								break;
						}
						default:
						{
								trigger_motor(10.0f);
								break;
						}
				}
		}
	#endif
		static int8_t ctal;
		if(shoot_control.shoot_rc->key.v & KEY_PRESSED_OFFSET_CTRL)
		 ctal = 1;
	 else
		 ctal = 0;
//		if(robot_state.remain_HP<15 && ctal == 0)
//				trigger_motor(0);
		if(ctal)
			trigger_motor(10.0f);		
		if(abs(shoot_control.fric_left_motor_measure->speed_rpm)<3900 || abs(shoot_control.fric_right_motor_measure->speed_rpm)<3900)
				trigger_motor(0);
		shoot_control.shoot_time++;
		if(shoot_control.shoot_time >= 150) shoot_control.shoot_time = 150;
		press_l_last_s = shoot_control.press_l;

}

/**
  * @brief          电机速度计算
  * @param[in]      void
  * @retval         void
  */
static void shoot_control_loop(void)
{
			shoot_laser_on();
			//计算pid
			PID_calc(&shoot_control.trigger_pid, shoot_control.trigger_speed, shoot_control.trigger_speed_set);
			PID_calc(&shoot_control.fric_left_pid, shoot_control.fric_left_speed, shoot_control.fric_left_speed_set);
			PID_calc(&shoot_control.fric_right_pid, shoot_control.fric_right_speed, shoot_control.fric_right_speed_set);
			trigger_can_set_current = shoot_control.trigger_pid.out;
			left_can_set_current = shoot_control.fric_left_pid.out;
			right_can_set_current = shoot_control.fric_right_pid.out;
}

/**
  * @brief          射击数据更新
  * @param[in]      void
  * @retval         void
  */
static void shoot_feedback_update(void)
{

    static fp32 speed_fliter_1 = 0.0f;
    static fp32 speed_fliter_2 = 0.0f;
    static fp32 speed_fliter_3 = 0.0f;
	
    //拨弹轮电机速度滤波一下
    static const fp32 fliter_num[3] = {1.725709860247969f, -0.75594777109163436f, 0.030237910843665373f};

    //二阶低通滤波
    speed_fliter_1 = speed_fliter_2;
    speed_fliter_2 = speed_fliter_3;
    speed_fliter_3 = speed_fliter_2 * fliter_num[0] + speed_fliter_1 * fliter_num[1] + (shoot_control.trigger_motor_measure->speed_rpm * MOTOR_RPM_TO_SPEED) * fliter_num[2];
    shoot_control.trigger_speed = speed_fliter_3;
		
		//电机速度更新
		shoot_control.fric_left_speed = shoot_control.fric_left_motor_measure->speed_rpm;
		shoot_control.fric_right_speed = shoot_control.fric_right_motor_measure->speed_rpm;
		
    //鼠标按键
    shoot_control.last_press_l = shoot_control.press_l;
    shoot_control.last_press_r = shoot_control.press_r;
    shoot_control.press_l = shoot_control.shoot_rc->mouse.press_l;
    shoot_control.press_r = shoot_control.shoot_rc->mouse.press_r;
		
}


/**
  * @brief          卡弹拨盘回拨
  * @param[in]      void
  * @retval         void
  */
static void trigger_motor_turn_back(void)
{
			//根据电流值和时间判断是否卡弹
			if(trigger_can_set_current < -7500.0f)
			{
					shoot_control.block_time ++;
					if(shoot_control.block_time > 500)
					{	
							shoot_control.stuck_flag = 1;
							shoot_control.block_time = 0;
					}
			}
			else
			{
					shoot_control.block_time = 0;
			}
			//卡弹回拨时间
			if(shoot_control.stuck_flag == 1)
			{
					shoot_control.reverse_time ++;
					if(shoot_control.reverse_time > 70)
					{
							shoot_control.reverse_time = 0;
							shoot_control.stuck_flag = 0;
					}
			}
}

