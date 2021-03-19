#include <stdio.h>
void main()
{
	int n = 10;
	int *np;
	np = &n;

	printf("%d %d\n", n, *np);
}
