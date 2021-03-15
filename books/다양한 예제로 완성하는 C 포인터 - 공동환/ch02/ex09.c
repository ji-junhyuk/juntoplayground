#include <stdio.h>
int main()
{
	char c = 'A';
	char *cp;
	char **cpp;
	cp = &c;
	cpp = &cp;
	printf("%d %p %p\n", c, cp, cpp);
	printf("%d %p %p\n", c + 1, cp + 1, cpp + 1);
}
