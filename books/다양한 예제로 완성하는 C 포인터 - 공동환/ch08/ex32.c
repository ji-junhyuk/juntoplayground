#include <stdio.h>
char* func()
{
	static char carr[100];

	fgets(carr, 100, stdin);
	return carr;
}

void main()
{
	char *str;

	str = func();
	printf("%s", str);
}
