#include <stdio.h>
void main()
{

	extern void entern_string(char str[]);
	extern void delete_string(char str[], char ch);
	extern void printf_string(char str[]);

	char c;
	char str[5];
	entern_string(str);

	scanf_s("%c",&c);
	delete_string(str, c);
	printf_string(str);
}



