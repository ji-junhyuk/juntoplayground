#include <stdio.h>
void main()
{
	int n = 10;
	const int * const np = &n;
	n = 20;

//	int m = 30;
//	*np = 30;
//	np = &m;

	printf("%d %d\n", n, *np);
}
