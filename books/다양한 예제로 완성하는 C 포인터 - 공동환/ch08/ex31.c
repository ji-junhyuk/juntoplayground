#include <stdio.h>
char *func(char *s)
{
	puts(s);
	return s;
}

void main()
{
	char *str;

	str = func("ABC");
	puts(str);
}
