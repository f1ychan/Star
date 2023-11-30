#include <stdio.h>
int deduct_bdlood();
int main()
{
	int a;
	float n;
	int maxblood;
	printf("请输入瞬时功率(>60)和最大血量\n");
	scanf_s("%d %d", &a, &maxblood);

	float k = (a - 60) / 60;
	if (k <= 0.1) {
		n = 0.1;
	}
	else if (0.1 < k <= 0.2) {
		n = 0.2;
	}
	if (k > 0.2) {
		n = 0.4;
	}
	printf("%f", maxblood * n * 0.1);
	return 0;
}
