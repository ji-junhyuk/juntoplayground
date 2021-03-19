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
	printf("%p %p\n", fp, func);
}
