#include <stdio.h>
void func(int n)
{
	static int sn = 10;
	printf("%d %d\n", n, sn);
}

void main()
{
	int m = 10;
	func(m);
}
