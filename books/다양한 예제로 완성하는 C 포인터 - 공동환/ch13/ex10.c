#include <stdio.h>
#include <string.h>
void main()
{
	char *str1 = "ABCDE";
	char *str2 = "ABDDE";

	printf("%d\n", strcmp(str1,str2));
	if (strcmp(str1, str2) == 0)
		puts("T");
	else
		puts("F");
}
