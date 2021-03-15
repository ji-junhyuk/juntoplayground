#include <stdio.h>
int main()
{
	int n = 20;
	int *np;
	int **npp;
	int ***nppp;
	np = &n;
	npp = &np;
	nppp = &npp;
	printf("%d %d %d %d\n", n, *np, **npp, ***nppp);
	printf("%p %p %p %p\n", &n, &np, &npp, &nppp);
	printf("%ld %ld %ld %ld\n", sizeof(int), sizeof(int *), sizeof(int **), sizeof(int ***));
	printf("%ld %ld %ld %ld\n", sizeof(n), sizeof(np), sizeof(npp), sizeof(nppp));
}
