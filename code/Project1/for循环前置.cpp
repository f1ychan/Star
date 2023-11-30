#include<stdio.h>

/*int main()
{
	int b;
	int c = 1;
	scanf_s("%d", &b);
	for (int a = 1; a <= b;a++) { c *= a; }
	printf("%d!=%d", b, c);
	return 0;
}*/
/*int main()
{
	int b;
	scanf_s("%d", &b);
	int c = 1;
	int a = 1;
	while (a <= b) {
		c *= a;
		a++;
	}
	printf("%d!=%d", b, c);
	return 0;
}*/

int main()
{
	int b = 0;
	int a = 0;
	int c = 1;
	scanf_s("%d", &b);//输入值  //如果a比要算的数小，把a加一挨个试试，但不可相等。
	for (a = 2; a < b; a++) { if (b % a == 0) { /*coutinue放弃下方语句结束循环*/c = 0;/*break用于句后跳出循环*/; } }
	if (c == 1) { printf("%d是素数", b); }//中途被任何数整除，c变成0，判为非素数
	else if (c == 0) { printf("%d不是素数", b); }
	return 0;
}
//尤其注意注意注意，=和==的区分。
//也请注意for的用法，（前提，进行的条件，结果）{循环体}，且只当胜利运行后，结果才会起作用。