#include<stdio.h>
int romd(y, m, d);
int main()
{
	int y, m, d, a;
	printf("请输入年月日：\n");
	scanf_s("%d %d %d", &y, &m, &d);
	a = romd(y, m, d);
	printf("是第%d天\n", a);
	return 0;
}

int romd(y, m, d) {
	int M[12] = { 31,28,31,30,31,31,31,31,30,31,30,31 };
	int b = 0;
	int i;
	for (i = 0; i < m - 1; i++) {
		b += M[i];
	}
	b += d;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0); {
		if (m > 2) {
			b++;
		}	}
	return b;
}
