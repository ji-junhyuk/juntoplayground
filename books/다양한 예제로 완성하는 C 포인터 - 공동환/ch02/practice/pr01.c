#include <stdio.h>
int main()
{
	char c = 'Z';
	char *cp = &c;
	int n = 100;
	int *np = &n;
	printf("%c %d\n", c, n);
	printf("%c %d\n", *cp, *np);
}
