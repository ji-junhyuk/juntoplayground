#include <stdio.h>
int main()
{
	char c = 'A';
	char *cp = &c;

	printf("%c %c %c\n", c, *cp, cp[0]);
}
