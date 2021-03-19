#include <stdio.h>
int func(int n1, int n2)
{
	return n1+n2;
}

void main()
{
	int sum;

	sum = func(5,3);
	printf("%d\n", sum);
}
