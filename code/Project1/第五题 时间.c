#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf_s("%d .%d", &a, &b);
	scanf_s(" %d. %d", &c, &d);
	if (b + d >= 60) {
		printf("%d %d", a + c + 1, b + d - 60);
	}
	else if (b + d < 60) {
		printf("%d %d", a + c, b + d);
	}

	return 0;
}
