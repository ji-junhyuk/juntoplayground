#include <stdio.h>
void func(int n1)
{
	int n2 = 20;
	printf("%d %d\n", n1, n2);
}

void main()
{
	int m = 100;
	func(m);
}
