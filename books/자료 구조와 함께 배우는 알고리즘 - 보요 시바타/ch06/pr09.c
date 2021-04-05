#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void insertion(int a[], int n)
{
	int i, j, m;
	for (i = 1; i < n; i++)
	{
		int tmp = a[0] = a[i];
		for (j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		if (j) a[j] = tmp;
	}
}

int main()
{
	int i, nx;
	int *x;

	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	i = 1;
	while (i < nx + 1)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}

	insertion(x, nx+1);

	for (i = 1; i < nx+1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
