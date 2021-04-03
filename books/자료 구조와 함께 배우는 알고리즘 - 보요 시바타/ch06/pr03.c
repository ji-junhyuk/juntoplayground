#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void bubble(int a[], int n)
{
	int i, j, m;
	int comparison = 0;
	int exchange = 0;
	i = 0;
	while (i < n - 1)
	{
		printf("패스%d:\n", i+1);
		j = n - 1;
		while (j > i)
		{
			for (m = 0; m < n; m++)
				printf("%2d %c", a[m], (m != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');
			puts("");

			comparison++;
			if (a[j - 1] > a[j])
			{
				exchange++;
				swap(int, a[j - 1], a[j]);
			}
			j--;
		}
		i++;
	}
	printf("comparison: %d회\n", comparison);
	printf("exchange: %d회\n", exchange);
}

int is_sorted(const int a[], int n)
{
	int i, j;
	int exchange = 0;

	i = 0;
	while (i < n - 1)
	{
		j = n - 1;
		while (j > i)
		{
			if (a[j - 1] > a[j])
			{
				exchange++;
				return 0;
			}
			j--;
		}
		if (exchange == 0)
			return 1;
		i++;
	}
}

int main()
{
	int i, nx;
	int x[] = {6,4,3,7,1,9,8};
 //	int *x;
 //
 //	nx = 5;
 //	x = calloc(nx, sizeof(int));
 //
 //	srand(time(NULL));
 //	i = 0;
 //	while (i < nx)
 //	{
 //		x[i] = 5 - i;
 //		i++;
 //	}

	nx = 7;
	printf("is_sorted: %d\n", is_sorted(x, 7));
	bubble(x, nx);
	printf("is_sorted: %d\n", is_sorted(x, 7));

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

//	free(x);

	return 0;
}
