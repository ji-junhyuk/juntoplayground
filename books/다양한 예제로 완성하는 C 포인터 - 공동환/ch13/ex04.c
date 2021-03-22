#include <stdio.h>
#include <string.h>
void main()
{
	char *str1 = "ABCDE";
	char *str2 = "12345";

	strcpy(str2, str1);

	printf("%s %s\n", str1, str2);
}
