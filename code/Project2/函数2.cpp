#include <stdio.h>
void delete_string(char str[], char ch)
{
	int i, j;
	for (i = j = 0;str[i] != '\0';i++, j++)
	{
		if (str[i] != ch) {
			str[j] = str[i];
		}
	}
	str[j] = '\0';
}