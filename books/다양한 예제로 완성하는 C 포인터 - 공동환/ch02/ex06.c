#include <stdio.h>
int main()
{
	int n = 20;
	int *np;
	int **npp;
	np = &n;
	npp = &np;
	printf("%d %d %d\n", n, *np, **npp);
	printf("%p %p %p\n", &n, np, *npp);
}
