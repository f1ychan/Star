#include <stdio.h>

int main()
{
	int t1 = 0;
	int t2 = 0;
	int t3;
	int t4;
	int t5;
	scanf_s("%d,%d", t1, t2);
	t3 = t1 / 100 * 60 + t1 % 100;
	t4 = t3 + t2;
	t5 = t4 / 60 * 100 + t4 % 60;
	printf("%d", t5);

	return 0;
}