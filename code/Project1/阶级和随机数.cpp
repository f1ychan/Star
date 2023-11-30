#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	int b, c, d;
	printf("A玩家为起始玩家,输入1开始选定数字");
	scanf_s("%d", &d);
	if (d == 1) {
		srand(time_t(0));
		int b = rand() % 7 + 1;
		int c = rand() % 7 + 1;
		printf("A玩家数字为%d，B玩家数字为%d", c, b);
		if (c > b) { printf("A玩家胜利"); }
		else if (b > c) { printf("B玩家胜利"); }
	}
	else if (d != 1) { printf("错误"); }
	return 0;
}