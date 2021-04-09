#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void bubble(int a[], int n)
{
	int i, j, m, exchange;

	i = 0;
	while (i < n - 1)
	{
		printf("패스%d:\n", i+1);
		exchange = 0;
		j = n - 1;
		while (j > i)
		{
			for (m = 0; m < n - 1; m++)
				printf("%2d %c", a[m], (m != j-1) ? '-' : (a[j - 1] > a[j]) ? '+' : '-');
			printf("%2d\n", a[m]);

			if (a[j - 1] > a[j])
			{
				exchange++;
				swap(int, a[j - 1], a[j]);
			}
			j--;
		}
		if (exchange == 0)
			break;
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
