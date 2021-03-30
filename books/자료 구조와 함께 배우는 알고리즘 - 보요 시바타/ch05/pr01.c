#include <stdio.h>
int factorial(int n)
{
	int i, sum;
	i = 1;
	sum = 1;
	while (i <= n)
	{
		sum *= i;
		i++;
	}
	return sum;
}

int main()
{
	int n;
	n = 5;
	printf("sum: %d\n", factorial(n));

	return 0;
}
