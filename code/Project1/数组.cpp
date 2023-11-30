#include <stdio.h>
#include <string.h>
/*int main()
{
	int x;
	double sum = 0;
	int cut = 0;
	int number[100];
	scanf_s("%d", &x);
	while (x != -1) {
		number[cut] = x;
		sum += x;
		cut++;
		scanf_s("%d", &x);
	}
	if (cut > 0) {
		printf("%f\n", sum / cut);
		int i;
		for (i = 0;i < cut;i++) {
			if (number[i] > sum / cut) {
				printf("%d\n", number[i]);
			}
		}

	}
	return 0;
}*/


/*int main()
{   //a[0]访问第一个元素，从0计算
	//int a[5]创建数组，a[5]访问数组且报错,访问从0开始 数组第几个数加一
	//int a[5]创建数组,a[0],a[1],a[2],a[3],a[4]


	int a[10];
	int sun = 0;
	int i;
	for (i = 0;i < 10;i++) {
		a[i] = i;
		printf("第%d位同学的成绩是", i + 1);
		scanf_s("%d", &a[i]);
		sun += a[i];
	}
	printf("平均成绩为%.2f", (double)sun / i);
	return 0;
}
//scanf对于数组运用，数组录入，小数点保留*/


/*int main() {
	//int a[10]={0}是把第一个元素赋值0，
	//int a[10]={0,1,2,3,4,5,6,7,8,9};赋值给不同的值
	//int a[10] = { 0 };//全部为0
	//int a[10]{[5]=6,[6]=7};单个赋值
	int a[10];//不赋值
	//int c[10] = { 1,2,5,6 };剩下自动赋值为0；
	int i;
	for (i = 0;i < 10;i++) {
		a[i] = i;
		printf("%d\n", a[i]);
	}
}*/

/*int main()
{
	int i = 0;
	char a[11];
	printf("请开始输入字符：");
	//getchar();//消掉空格，多出一个位置
	for (i = 0;i < 11;i++) {
		scanf_s("%c", &a[i], 1);
	}
	printf("你的字符串是：%s", a);
	return 0;
}*/


/*int main()
{
	int a[10];
	int i = 0;
	for (i = 0;i < 10;i++) {
		a[i] = i;
	}
	for (i = 0;i < 10;i++) {
		printf("%d\n", &a[i]);
	}
	return 0;
}*///说明vs不适应数组溢出的情况；

/*int main() {
	char a[] = "i love sxy";
	printf("sizeof=%d\n", sizeof(a));//包括最后的\0
	printf("strlen=%d\n", strlen(a));//字符个数
	return 0;
}*/

/*int main()
{
	char str1[] = "i love sxyyyyyy";
	char str2[] = "i like sxy";
	char str3[100];

	strcpy_s(str1, str2);
	strcpy_s(str3, "deeplove");

	printf("1；%s\n", str1);
	printf("2；%s\n", str2);
	printf("3；%s\n", str3);

	return 0;
}*/

/*int main()
{
	char str1[] = "i love love sxy";
	char str2[40];

	strncpy_s(str2, str1, 5);
	str2 [5] = '\0';
	printf("%s\n", str2);
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////
/*int main()
{
	char str1[] = "i";
	char str2[] = "love sxy";

	strcat_s(str1, "");
	strcat_s(str1, str2);

	printf("%s\n", str1);
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	char str1[] = "i love sxy";
	char str2[] = "i love sxy";

	if (!strcmp(str1, str2)) {
		printf("两个字符串一致!\n");
	}

	else {
		printf("两个字符串存在差异!\n");
	}
	return 0;
}




