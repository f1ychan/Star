
int pushButton =2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//串口通讯初始化,数据传输速率每秒9600位，之前通过灯来看工作情况，现在将运行状态发送到电脑屏幕
  pinMode(pushButton,INPUT);//相反与OUTPUT，这是向电脑传输电平信号
}

void loop() {
  // put your main code here, to run repeatedly:
  int Buttonstate =digitalRead(pushButton);//读取输入引脚高低电平
  Serial.println(Buttonstate);//显示引脚状态，类似于printf
  delay(1);
  }
