#include <stdio.h>
int func(int n1, int n2)
{
	printf("%d %d\n", n1, n2);
	return n1+n2;
}
void main()
{
	int (*fp)(int, int);
	fp = func;

	func(5, 5);
	fp(5, 5);
}
