#include <stdio.h>
int main()
{
	char c = 'A';
	char *cp = &c;
	printf("%c %c\n", c, *cp);
	printf("%ld %ld\n", sizeof(char), sizeof(char *));
	printf("%ld %ld\n", sizeof(c), sizeof(cp));
}
