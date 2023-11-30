#include<stdio.h>

int main()
{
	int b = 2;
	int a = 0;

	while (b <= 10) {
		int c = 1;
		for (a = 2; a < b; a++) { if (b % a == 0) { c = 0; } }
		if (c == 1) { printf("%d ", b); }
		b++;
	}
	return 0;
}
