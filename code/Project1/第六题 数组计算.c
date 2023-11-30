#include<stdio.h>
int main()
{//学长这个地方我应该疏忽了，没有去学习，数太大了直接给我判0
	int a = 2;
	int b = 1;
	int c = 3;

	do {
		b = c;
		if (c % 2 == 0) {
			a *= b;
		}
		else if (c % 2 != 0) {
			b = b * 2;
			a *= b;
		}
		c++;
	} while (c <= 100);
	printf("%d", a * 101);
	return 0;
}



