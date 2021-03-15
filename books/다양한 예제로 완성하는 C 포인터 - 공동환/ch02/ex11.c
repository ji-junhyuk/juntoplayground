#include <stdio.h>
int main()
{
	int n = 20;
	int *np;
	int **npp;
	np = &n;
	npp = &np;
	printf("%d %p %p\n", n, np, npp);
	printf("%d %p %p\n", n + 1, np + 1, npp + 1);	
}
