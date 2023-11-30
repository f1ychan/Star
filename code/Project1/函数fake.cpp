#include <stdio.h>
/*int main()
{
	int m, n;
	int sun = 0;
	int d = 0;
	int e = 1;		·	z45ESZFYU890R
	scanf_s("%d %d", &m, &n);
	for (int c = m;c <= n;c++) {
		e = 1;
		for (int a = 2;a < c;a++) {
			if (c % a == 0) { e = 0;break; }
		}if (e == 1) { sun += c;d++; }
	}
	printf("%d %d", sun, d);


	return 0;

}*/
//a<c-1可提高效率；



/*int isPrime(int c) {
	int e = 1;
	for (int a = 2;a < c;a++) {
		if (c % a == 0) { e = 0;break; }
	}
	return e;//return回第一个变量
}
int main()
{
	int m, n;
	int sun = 0;
	int d = 0;
	scanf_s("%d %d", &m, &n);
	for (int c = m;c <= n;c++) {
		if (isPrime(c)) { sun += c;d++; }
	}
	printf("%d %d", sun, d);


	return 0;

}*/
//a<c-1可提高效率；



void cheer(int i)
{
	printf("%d/", i);
}
int main()
{
	cheer();
	return 0;
}//cheer()和main()内变量传递



/*void swap(int a, int b);//函数不放在首行要提前声明
int main()
{
	int a = 5;
	int b = 6;
	swap(a, b);//本函数main中啊a,b值已经确定，与swap无关
	p
}*/





