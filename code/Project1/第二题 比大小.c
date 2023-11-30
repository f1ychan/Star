#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	int a = 0;
	int d = 0;
	int c, b;
	printf("AB输入未学会，用1,2代替了，不好意思\n");
	printf("输入1开始选定数字\n");
	scanf_s("%d", &d);
	if (d == 1) {
		srand(time_t(0));
		int b = rand() % 7 + 1;
		int c = rand() % 7 + 1;
		printf("到你了\n");
		scanf_s("%d", &a);
		if (a == 2) {
			printf("A玩家数字为%d，B玩家数字为%d\n", c, b);
			if (c > b) { printf("A玩家胜利\n"); }
			else if (b > c) { printf("B玩家胜利\n"); }
		}

	}

	return 0;
}