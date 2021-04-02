#include <stdio.h>

int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main()
{
	int x;
	printf("x: ");
	scanf("%d", &x);
	printf("%d factorial: %d\n", x, factorial(x));

	return 0;
}
