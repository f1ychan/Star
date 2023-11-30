#include <stdio.h>
int  left_move();
int  left_move(char rm[], int k) {
	for (int c = k;c < 10;c++) {
		printf("%c", rm[c]);
	}
	for (int f = k;f >= 0; f--) {
		printf("%c", rm[f]);
	}
	return 0;

}
int main() {
	int k;
	char rm[10];
	for (int b = 0;b < 10; b++) {
		scanf_s("%c", &rm[b]);

	}
	printf("输入数字");
	scanf_s("%d", &k);
	left_move(rm, k);

}