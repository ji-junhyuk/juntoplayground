#include <stdio.h>
#include <stdlib.h>
void main()
{
	char *cp;
	cp = (char *)malloc(sizeof(char)*5);
	cp[0] = 1; cp[1] = 2; cp[2] = 3; cp[3] = 4; cp[4] = 5;

	printf("%d %d %d %d %d\n", cp[0], cp[1], cp[2], cp[3], cp[4]);
	free(cp);
}
