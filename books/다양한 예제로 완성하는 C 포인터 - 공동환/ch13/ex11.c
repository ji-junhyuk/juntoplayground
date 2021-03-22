#include <stdio.h>
#include <string.h>
void main()
{
	char *str1 = "ABCDE";
	char str2[100] = "ABCDE";

	if (str1 == str2)
		puts("T");
	else
		puts("F");
	if (strcmp(str1, str2) == 0)
		puts("T");
	else
		puts("F");
}
