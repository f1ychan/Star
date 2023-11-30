#include<stdio.h>
int main()
{
	int b, i, j;
	int a[] = { 9,7,6 };
	for (i = 0;i < 3;i++) {
		for (j = i + 1;j < 4;j++) {
			if (a[i] > a[j]) {
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}//运用冒泡比大小；
	for (int C = 0;C < 3;C++) {
		printf("%d\n", a[C]);
	}
	return 0;
}


