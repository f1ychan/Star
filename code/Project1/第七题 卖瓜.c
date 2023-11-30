#include<stdio.h>
int main()
{
	float a;
	int b = 1;
	scanf_s("%f", &a);
	a -= 1.5;
	do {
		a -= 1.5;
		b++;
	} while (a >= 0);
	printf("%d", b);
	return 0;
}