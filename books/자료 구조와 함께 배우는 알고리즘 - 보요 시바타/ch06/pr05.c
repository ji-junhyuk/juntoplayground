#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void bubble(int a[], int n)
{
	int i, j, k;
	int last; 
	int pass = 0;
	k = 0;
	while (k < n - 1)
	{
		pass++;
		printf("%d번째 패스: \n", pass);
		last = n - 1;
		j = n - 1;
		while (j > k)
		{
			for (i = 0; i < n - 1; i++)
				printf("%2d %c", a[i], (i != j-1) ? ' ' : (a[i] > a[i+1]) ? '+' : '-');
			printf("%2d\n", a[i]); 
			if (a[j - 1] > a[j])
			{
				swap(int, a[j-1], a[j]);
				last = j;
			}
			j--;
		}
		k = last;
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
