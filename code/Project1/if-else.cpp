#include <stdio.h>

int main()
{
	int a = 0;
	scanf_s("%d", &a);
	if (a == 1) { printf("星期一"); }
	else if (a == 2) { printf("星期二"); }
	else if (a == 3) { printf("星期三"); }
	else if (a == 4) { printf("星期四"); }
	else if (a == 5) { printf("星期五"); }
	else if (a == 6) { printf("星期六"); }
	else if (a == 7) { printf("星期天"); }
	else if (a == 8) { printf("错误"); }

	return 0;
}
