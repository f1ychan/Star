#include<stdio.h>

int rom(a);
int main()
{
	int a;
	scanf_s("%d", &a);
	rom(a);
	return 0;
}

int rom(a) {
	int b = a;
	do {
		for (int i = 1;i <= b;i++) { printf("%d", i); }
		for (int k = b - 1;k >= 1;k--) { printf("%d", k); }
		b--;
		printf("\n");
		for (int c = b;c <= a;c++) {
			printf(" ");
		}

	} while (b != 0);
}