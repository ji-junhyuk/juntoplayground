#include <stdio.h>
void func(int n1)
{
	auto int n2 = 20;
	printf("%d %d\n", n1, n2);
}

void main()
{
	auto int m = 100;
	func(m);
}
