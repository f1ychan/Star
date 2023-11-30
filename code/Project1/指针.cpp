#include <stdio.h>
/*int main()
{
	char a = 'F';
	int  b = 123;// 变量 和 地址

	char* pa = &a;
	int* pb = &b;//指针变量 和 取地址(获取变量地址)

	printf("变量a的地址=%c\n", *pa);
	printf("变量a的地址=%c\n", a);

	//改地址
	*pa = 'C';
	*pb += 1;

	printf("sizeof pa=%d\n", sizeof(pa));
	printf("sizeof pb=%d\n", sizeof(pb));//获取字节都一样  说明指针指向地址大小都一样，
	//地址是指针本身存储位位置
	printf("sizeof a=%d\n", sizeof(a));
	printf("sizeof b=%d\n", sizeof(a));


	printf("address a=%p\n", pa);
	printf("address b=%p\n", pb);
	//说明地址不同，地址大小一样



	return 0;
}*/

/*int main()
{
	int a;
	int* p = &a;

	scanf_s("%d", &a);
	printf("a的地址是%d\n", a);


	printf("输入重新的赋值：\n");
	scanf_s("%d", p);//p和%a是一样的
	printf("a的地址是%d", a);
	return 0;
}*/

/*int main()
{
	char a[5] = "asds";


	printf("%p\n", &a);
	printf("%p\n", &a[0]);
	return 0;
}//证明数字地址就是零号元素地址*/

/*/int main()
{
	char a[5] = "love";
	char* p = a;
	printf("%c %c\n %c\n", *p, *(p + 1), a[0]);
}//单个访问*(p+1)*/

/*int main()
{
	int count = 0;
	char a[] = "ilovec";
	char* p = a;
	while (*(p++) != '\0') {
		count++;
	}
	printf("%d", count);
	return 0;

}//*p和*(p++)是一样的
*/

///////////////////指针数组和数组指针



/*const char* word(char);
const char* word(char C) {

	switch (C)
	{
	case'A': return "apple";
	case'B': return "bag";
	case'C': return "city";
	case'D': return "dog";
	default: return "none";
	}
}
int main()
{
	char C;
	printf("输入你的字母");
	scanf_s("%c", &C);
	printf("抽取的单词为:%s\n", word(C));
	//printf("抽取的单词为:%s\n", *word(C));获取city的地址即为整形，是错误的
	return 0;
}*/





/*void max_min_value(int str[], int n);
int max, min;
void main()
{
	int i, str1[10];//形参和实参变量名的不同，但变量要想同样
	printf("输入十个数字\n");
	for (int i = 0;i < 10;i++)
	{
		scanf_s("%d", &str1[i]);
	}
	max_min_value(str1, 10);
	printf("max=%d,min=%d\n", max, min);
}
void max_min_value(int str[], int n)//要加[]以确定为数组
{
	int* p, * str2;
	str2 = str + n;//str2是 str+n 地址
	max = min = *str;
	for (p = str + 1;p < str2;p++)
		//str+1是跳过首元素，str2是指最后一个元素，此处都是地址
	{
		if (*p > max) {
			max = *p;
		}
		else if (*p < min) {
			min = *p;
		}

	}

}*/
/*int main()
{
	int a[3][4] = { (1,2,3,4),(5,6,7,8),(9,0,2,3) };
	printf("%d\n", a[0]);
	printf("%d\n", *a);
	printf("%d", &a);
}*/

/*int main()
{

	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };//二维数组就是地址套地址，最后是元素
	int(*p)[4];//相当于把  二维数组  解算成四个  一维数组  地址的数组
	//p 是一个指针，它指向一个包含 5 个 int 类型数据的数组
	p = a;//把p定义为a[0][0]的  地址，是地址而不是a[0][0]
	printf("%d\n", p);
	printf("%d\n", a);
	printf("%d\n", *a);//*a就是获取a[0][0]地址，和a是一样的
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%d\n", *(*(p + i) + j));//*（p+i）是指获取第一行【0】的地址加j获取行列地址，最后整体解算
		}
	}
	return 0;

}*/
/*int main()
{

//////////////////////////////////
	int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int c, b;
	scanf_s("%d %d", &c, &b);
	printf("%d", a[c][b]);
/////////////////////////////////


	int(*p)[4], a, b;
	int c[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	p = c;
	printf("i=");
	scanf_s("%d", &a);
	while (a < 0 || a>2) {
		printf("错误，请重新输入i=");
		scanf_s("%d", &a);
	}
	printf("j=");
	scanf_s("%d", &b);
	while (a < 0 || a>2)
	{
		printf("错误，请重新输入j=");
		scanf_s("%d", &b);
	}
	printf("c[%d][%d]=%d", a, b, *(*(p + a) + b));

	return 0;
}*/


int main() {
	char string[] = "i love china!\n";
	const char* string1 = "i love china!";
	printf("%s", string);
	printf("%s", string1);
	return 0;
}
