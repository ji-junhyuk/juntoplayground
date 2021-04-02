#include <stdio.h>
#include <stdlib.h>
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		gcd(y, x%y);
}

int gcd_array(const int a[], int n)
{
	if (n == 1)
		return a[0];
	else if (n == 2)
		return gcd(a[0], a[1]);
	else
		return gcd(a[0], gcd_array(&a[1], n - 1)); 
}

int main()
{
	int i, nx;
	int *x;

	nx = 5;
	x = (int *)calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}

	printf("gcd: %d\n", gcd_array(x, nx));

	free(x);

	return 0;
}
