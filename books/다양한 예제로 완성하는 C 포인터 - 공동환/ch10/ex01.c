#include <stdio.h>
#include <stdlib.h>
void main()
{
	char *cp;

	cp = (char *)malloc(1);
	*cp = 'A';

	printf("%c\n", *cp);
	free(cp);
}
