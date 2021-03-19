#include <stdio.h>
int Add(int n1, int n2)
{
	printf("%d %d\n", n1, n2);
	return n1+n2;
}

void main()
{
	printf("10 + 20 = %d", Add(10, 20));
}
