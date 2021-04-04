#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void insertion(int a[], int n)
{
	int i, j, m;
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];

		for (m = 0; m < n; m++)
			printf("%3d ", a[m]);
		puts("");
		
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;

		printf("i의 값: %d, j의 값: %d\n", i, j);
		printf("%*s%s", 4 * j, "", (i !=j) ? "^-" : " ");
		for (m = 0; m < 4 * (i - j); m++)
			putchar('-');
		printf("+\n\n");
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

	insertion(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
