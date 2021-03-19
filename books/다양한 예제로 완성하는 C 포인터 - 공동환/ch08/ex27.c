#include <stdio.h>
void func(int *np)
{
	*np = 33;
}

void main()
{
	int n = 10;

	printf("%d\n", n);
	func(&n);
	printf("%d\n", n);
}
