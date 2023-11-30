#include <stdio.h>
int main()
{
	int a;
	int b = 0;
	int j, k, i;
	scanf_s("%d", &a);
	for (j = a;j <= a + 3; j++) {
		for (k = a;k <= a + 3; k++) {
			for (i = a;i <= a + 3;i++) {
				if (i != j && k != j && i != k) {
					printf("%d%d%d", i, j, k);
					b++;
					if (b <= 5) { printf(" "); }//换行符是用于上个语句，让下一个换行
					else { printf("\n");b = 0; }
				}
			}
		}


	}

	return 0;
}
//while是一次性循环一旦符合一直进入，if是多次循环一旦符合，返回上层；
// while{}是指满足条件时进入循环     do，while{},while()----->进入do;


