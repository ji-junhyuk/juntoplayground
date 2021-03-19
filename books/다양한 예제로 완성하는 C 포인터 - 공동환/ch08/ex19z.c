#include <stdio.h>
void func(int *ip)
{
	printf("%p %d\n", ip, *ip);
}

void main()
{
	int n = 10;
	func(&n);
}
