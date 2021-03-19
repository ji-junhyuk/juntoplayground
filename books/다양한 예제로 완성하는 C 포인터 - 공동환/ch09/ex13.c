#include <stdio.h>
void main()
{
	int n = 10;
	int *np = &n;
	int **npp;

	npp = &np;

	printf("%d %d\n", n, **npp);
}
