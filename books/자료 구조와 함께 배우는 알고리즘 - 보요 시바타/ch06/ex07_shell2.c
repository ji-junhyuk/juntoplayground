#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
	int i, j, h;

	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	for (; h > 0; h /= 3)
		for (i = h; i < n; i++)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
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

	shell(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
