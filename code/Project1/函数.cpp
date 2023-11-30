#include <stdio.h>
/*void print_x();
void print_x() {
	printf("#########");

}
int main()
{
	print_x();
	printf("\n");
	print_x();
	printf("\n");
	print_x();
	return 0;

}*/


/*int Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int IsLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int days(int year, int month, int day)   //函数功能---计算天数
{
	int i;
	int sum = 0;
	for (i = 0; i < month - 1; i++)
	{
		sum += Month[i];
	}
	sum += day;      //加上当月天数
	if (IsLeap(year) == 1 && month > 2)
	{
		sum++;
	}
	return sum;
}
int main()
{
	int year, month, day;
	printf("请输入日期（年，月，日）\n");
	scanf_s("%d,%d,%d", &year, &month, &day);
	int ret = days(year, month, day);
	printf("\n%d月%d日是%d年的第%d天。", month, day, year, ret);
}*/

/*void averager(int array[4]);//取最大值最小值和平均值
int max;
int min;
int ave;
int main()
{
	int score[4];
	printf("代码运行成功，输入十个数字\n");
	for (int i = 0;i < 4;i++) {
		scanf_s("%d", &score[i]);
	}
	averager(score);
	printf("%d %d %d", max, min, ave);
	return 0;
}
void averager(int array[4])
{
	int k = 0;
	max, min = array[0];
	for (int o = 1;o < 4;o++) {
		if (array[o] > max) {
			max = array[o];
		}
		if (array[o] < min) {
			min = array[o];
		}
		k += array[o];
	}
	ave = k / 4;
}*/

/*int f(int a) {
	int b = 0;
	static int c = 3;
	b = b + 1;
	c = c + 1;

	return (a + b + c);
}
int main() {
	int a = 2;
	f(a);
	for (int i = 0;i < 3;i++) {
		printf("%d\n", f(a));
	}
	return 0;
}*///static会使c变量在函数调用后不会销毁

//阶乘的多种方法
/*int f(int n) {..
	int a = n;
	if (n == 0) {
		return (1);
	}
	if (n != 0) {
		for (int i = 1;i < n;i++) {
			a = n * f(n - 1);//执行操作为n*n-1*n-1-1等等
		}
	}
	return (a);
}
int main() {
	int b;
	scanf_s("%d", &b);
	printf("%d的阶乘是%d", b, f(b));
	return 0;
}*///递归的办法

int f(int a) {
	static int b = 1;//1,2,3*2*1,
	b = b * a;//1,2*1,3*2*1,4*3*2*1
	return b;
}
int main() {
	int i;
	for (i = 1;i < 6;i++) {
		printf("%d的阶乘是%d\n", i, f(i));
	}
	return 0;
}//静态变量的办法

//extern定义扩大作用于，也可用于外部，属于声明从外部获取变量
//register定义放于寄存器中
//static定义函数或者变量以后不可跨文件使用，跨文件必须加extern


