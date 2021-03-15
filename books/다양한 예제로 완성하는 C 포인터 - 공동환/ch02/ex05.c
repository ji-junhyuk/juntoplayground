#include <stdio.h>
int main()
{
	char c = 'A';
	char *cp;
	char **cpp;

	cp = &c;
	cpp = &cp;
	printf("%c %c %c\n", c, *cp, **cpp);
	printf("%p %p %p\n", &c, cp, *cpp);
}
