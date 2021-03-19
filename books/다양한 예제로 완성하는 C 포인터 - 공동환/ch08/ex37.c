#include <stdio.h>
int func()
{
	int m = 10;

	return m;
}

void main()
{
	int n;

	n = func();

	printf("%d\n", n);
}
