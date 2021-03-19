#include <stdio.h>
int n = 20;

int *func()
{
	return &n;
}

void main()
{
	int *np;

	np = func();
	printf("%d %d\n", n, *np);
}
