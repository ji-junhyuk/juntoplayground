#include <stdio.h>
int Factorial(int n)
{
	return n == 0 ? 1 : n * Factorial(n-1);
}

void main()
{
	printf("3! = %d", Factorial(3));
}
