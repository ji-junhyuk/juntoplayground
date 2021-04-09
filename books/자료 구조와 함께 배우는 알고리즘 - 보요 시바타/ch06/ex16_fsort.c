#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max)
{
	int i;
	int *f = calloc(max + 1, sizeof(int));
	int *b = calloc(n, sizeof(int));

	for (i = 0; i <= max; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i]]++;
	for (i = 1; i <= max; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

int main()
{
	int i, nx;
	int *x;
	const int max = 100;
	printf("max: 100, nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	fsort(x, nx, max);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
