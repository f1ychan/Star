#include <stdio.h>
int rom(a);
int main()
{
	int a, b;
	scanf_s("%d", &a);
	b = rom(a);
	printf("count=%d", b);
	printf("学长，这道题按照100为起始来算，确实7个数啊\n");
	return 0;
}
int rom(a) {
	int c = 0;
	int b;
	for (int i = 100;i <= a;i++) {
		if (i % 10 == i / 100 || i % 10 == i % 100 / 10 || i % 100 / 10 == i / 100) {
			for (b = 10;b <= 32;b++) {
				if (b * b == i) {
					printf("%d\n", i);
					c++;
				}

			}


		}
	}
	return c;
}
