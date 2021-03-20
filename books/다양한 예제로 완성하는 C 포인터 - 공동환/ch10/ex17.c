#include <stdio.h>
void main()
{
	int n = 10;
	const int *np = &n;

	n = 20;
//	*np = 30;
	printf("%d %d\n", n, *np);
}
