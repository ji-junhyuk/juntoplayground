#include <stdio.h>
#include <stdlib.h>
void main()
{
	char *cp;
	cp = (char *)malloc(sizeof(char));
	*cp = 'A';

	printf("%c\n", *cp);
	free(cp);

	int *ip;
	ip = (int *)malloc(sizeof(int));
	*ip = 500;

	printf("%d\n", *ip);
	free(ip);
}
