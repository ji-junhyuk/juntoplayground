#include <stdio.h>
void main()
{
	char c = 'A';
	char *cp = &c;

	printf("%c\n", *cp++);
	printf("%c\n", *--cp);
	printf("%c\n", (*cp)++);
	printf("%c\n", ++(*cp));
}
