#include <stdio.h>
void func(int n1, int n2, int *psum)
{
	*psum = n1 + n2;
}

void main()
{
	int sum;
	int a = 10, b = 20;

	func(a, b, &sum);
	printf("%d\n", sum);
}
