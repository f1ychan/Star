#include <stdio.h>
void rom(int a);
int main() {
	int a;
	scanf_s("%d", &a);
	rom(a);

	return 0;
}
void rom(int a) {
	int i;
	for (i = 1;i <= a;i++) {
		if (i % 2 == 0) {
			printf("% d\n", i);

		}
	}
}