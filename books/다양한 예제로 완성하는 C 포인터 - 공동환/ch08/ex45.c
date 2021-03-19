#include <stdio.h>
int Fibonacci(int n)
{
	return n <= 2 ? 1 : Fibonacci(n-2)+Fibonacci(n-1);
}

void main()
{
	printf("Fibonacci(5): %d", Fibonacci(5));
}

