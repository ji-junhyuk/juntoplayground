#include <stdio.h>
#include <string.h>
void main()
{
	char *str1 = "ABCDE";
	char str2[100];

	strcat(str2, str1);
	printf("%s %s\n", str1, str2);
}
