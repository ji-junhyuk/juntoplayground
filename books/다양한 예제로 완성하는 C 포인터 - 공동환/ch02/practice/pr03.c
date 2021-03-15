#include <stdio.h>
int main()
{
	int n = 10;
	int *np = &n;
	int **npp = &np;
	printf("%d %d %d\n", n, *np, **npp);
	printf("%ld %ld %ld\n", sizeof(n), sizeof(*np), sizeof(**npp));
	printf("%ld %ld %ld\n", sizeof(n), sizeof(np), sizeof(npp));
}
