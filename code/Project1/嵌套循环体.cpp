#include <stdio.h>
/*int main()
{
	int b = 0;
	int a = 0;
	int c = 1;
	scanf_s("%d", &b);
	for (a = 2; a < b; a++) { if (b % a == 0) { c = 0;break; } }
	if (c == 1) { printf("%d是素数", b); }
	else if (c == 0) { printf("%d不是素数", b); }
	return 0;

}*/

/*int main()
{
	int b;
	int a;
	for (b = 1;b <= 100;b++) {
		int c = 1;//要把int c放在里面才可以保证赋回原值
		for (a = 2; a < b; a++) { if (b % a == 0) { c = 0;break; } }
		if (c == 1) { printf("%d ", b); }//点个空格也会打印进去
	}
	return 0;

}*/


/*int main()
{
	int a;
	int b = 1;
	int c = 1;
	int d = 1;多余
	for (d = 1; d <= 100; d++) {
		b = d;
		c = 1;
		for (a = 2;a < d; a++) { if (b % a == 0) { c = 0; } }
		if (c == 1) { printf("%d ", b); }
	}

	return 0;
}*///100内素数fordor版
/*int main()
{
	int a;
	int b = 1;
	int c = 1;
	int d = 1;
	while (d <= 100) {
		b = d;
		c = 1;
		for (a = 2;a < d; a++) { if (b % a == 0) { c = 0; } }
		if (c == 1) { printf("%d ", b); }d++;
	}

	return 0;
}*///100内素数whilewhile版
/*int main()
{
	int a;
	int b = 1;
	int c = 1;
	int d;
	for (d = 1; b <= 100;d++) {//穿插变量b，而不是单一d，d++只会无限循环
		c = 1;
		for (a = 2;a < d; a++) { if (d % a == 0) { c = 0; } }
		if (c == 1) {
			printf("%d ", d);b++;
		}
	}
	return 0;
}*/


/*int main()
{
	int a;
	int b = 1;
	int c = 1;
	int d = 1;
	while (d <= 100) {
		c = 1;
		for (a = 2;a < b; a++) { if (b % a == 0) { c = 0; } }
		if (c == 1) { printf("%d ", b);d++; }
		b++;}
return 0;
}*///三个结构三个数字，一个作为检测素数程序，一个用于计算次数（必须放在if内），另个作为待检测数字（printf内容）
//循环一次while，b会加一，增加待检测数字，但只有在d符合for检测程序时，次数d增加

//break,if(){break}接力、、goto out out 类似与前面



//warning//warning//warning//warning//warning//warning//warning//warning//warning//warning
//warning//warning//warning//warning//warning//warning//warning//warning//warning//warning

//warning//warnin g//warning//warning//warning//warning//warning//warning//warning//warning
//warning//warning//warning//warning//warning//warning//warning//warning//warning//warning

//%取余数  /去掉尾数
/*int main()
{
	int a, b;
	scanf_s("%d", &a);
	do {
		b = a % 10;
		a /= 10;
		printf("%d ", b);
	} while (a > 0);

	return 0;
}*///逆序

/*int main()
{
	int a, b;
	scanf_s("%d", &a);
	do {
		b = a % 10;
		//a /= 10;54取完余数以后归为个位无空格
		printf("%d", b);
		if (a >= 10) {
			printf(" ");
		}
		a /= 10;
	} while (a > 0);

	return 0;
}*/

/*int main()
{
	int a, b;
	int t = 0;
	scanf_s("%d", &a);
	do {
		int d = a % 10;
		t = t * 10 + d;
		a /= 10;

	} while (a > 0);
	printf("%d", t);*/


	/*do {
		b = a % 10;
		printf("%d", b);
		if (a >= 10) {
			printf(" ");
		}
		a /= 10;
	} while (a > 0);

	return 0;
*/

//由于源程序无法获取007此类逆序，只输出7
// 以下为分解整数
//%取余数  /去掉尾数,
//  12345%10000=2345 
//  12345/10000=1

int main()
{
	int mask = 10000;
	int a;
	scanf_s("%d", &a);
	do {
		printf("%d", a / mask);
		if (mask > 9) {
			printf(" ");
		}
		a %= mask;//取出除了第一位的数字
		mask /= 10;
	} while (mask > 0);


	return 0;
}


