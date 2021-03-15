#include <stdio.h>
int main()
{
	int n = 0x10;
	int *np = &n;
	int **npp = &np;
	printf("%d %p %p\n", n, np, npp);
}
