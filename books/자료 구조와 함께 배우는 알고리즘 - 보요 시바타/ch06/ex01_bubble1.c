#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void bubble(int a[], int n)
{
	int i, j;

	i = 0;
	while (i < n - 1)
	{
		j = n - 1;
		while (j > i)
		{
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
			j--;
		}
		i++;
	}
}

int main()
{
	int i, nx;
	int *x;

	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}

	bubble(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
