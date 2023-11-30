#include <stdio.h>
#include <direct.h>
void entern_string(char str[5])
{
	for (int i = 0;i < 5;i++)
	{
		scanf_s("%c", &str[i]);
	}
	str[5] = '\0';
}
