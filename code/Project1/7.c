#include <stdio.h>
int main()
{
	int i, b, t;
	scanf_s("%d", &i);
	int a[11] = { 2,5,7,10,17,24,30,38,44,50,i };
	for (int c = 0;c < 10;c++) {
		for (int j = c + 1;j < 11;j++) {
			if (a[c] > a[j]) {
				b = a[c];
				a[c] = a[j];
				a[j] = b;
			}
		}
	}//c检索到前一个，b从第一个开始检索到最后一个；
	for (int C = 0;C < 11;C++) {
		printf("%d\n", a[C]);
	}
	return 0;
}