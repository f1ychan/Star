#include<stdio.h>
int main()
{
	int  footlong1, footlong2;
	printf("输入犯罪嫌疑人和犯罪现场的脚长");

	scanf_s("%d %d", &footlong1, &footlong2);
	compute(footlong2, footlong1);
	printf("%d", compute(footlong2, footlong1));
}
compute(footlong2, footlong1) {
	struct date {
		int error;
	};
	struct date s1 = {
		"7",
	};
	if (footlong2 > footlong1) {
		int c = footlong2 - footlong1;
		return(c * s1.error);
	}
	if (footlong1 > footlong2) {
		int b = (footlong1 - footlong2);
		return(b * s1.error);

	}
}