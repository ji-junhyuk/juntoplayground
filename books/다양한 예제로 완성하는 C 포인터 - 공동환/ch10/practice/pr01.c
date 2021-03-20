#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *np;

	np = (int *)malloc(sizeof(int));
	*np = 10;

	printf("%d\n", *np);

	free(np);
}
