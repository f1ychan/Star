#include <stdio.h>

int main()
{
	int b;
	int a[3];
	printf("输入数字元素");
	for (int i = 0;i < 3;i++) {
		scanf_s("%d", &a[i]);
	}
	printf("输入去掉的的数字\n");
	scanf_s("%d", &b);
	for (int i = 0;i < 2;i++) {
		if (b == a[i]) {
			for (int c = i;c < 2; c++);
			a[i] = a[i + 1];
			break;
		}
	}
	for (int i = 0;i < 2;i++) {
		printf("%d ", a[i]);
	}
	return 0;
}