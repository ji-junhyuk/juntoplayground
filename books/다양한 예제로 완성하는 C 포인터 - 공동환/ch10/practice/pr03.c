#include <stdio.h>
#include <stdlib.h>
char *inputStr()
{
	char *str2;
	str2 = (char *)malloc(sizeof(char) * 100);
	scanf("%s", str2);
	return str2;
}

void main()
{
	char *str;

	str = inputStr();

	printf("%s\n", str);

	free(str);
}
