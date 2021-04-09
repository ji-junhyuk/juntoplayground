#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max)
{
	int i;
	int *f = calloc(max + 1, sizeof(int));
	int *b = calloc(n, sizeof(int));

	puts("\n정렬 전 배열");
	for (i = 0; i < n; i++)printf("%3d", i); putchar('\n');
	for (i = 0; i < n; i++)printf("%3d", a[i]); putchar('\n');

	for (i = 0; i <= max; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i]]++;

	puts("\n도수 분포");
	for (i = 0; i < max; i++) printf("%3d", i); putchar('\n');
	for (i = 0; i < max; i++) printf("%3d", f[i]); putchar('\n');

	for (i = 1; i <= max; i++) f[i] += f[i - 1];

	puts("\n누적 도수 본포");
	for (i = 0; i < max; i++) printf("%3d", i); putchar('\n');
	for (i = 0; i < max; i++) printf("%3d", f[i]); putchar('\n');

	putchar('\n');

	for (i = n - 1; i >= 0; i--) 
	{
		b[--f[a[i]]] = a[i];
		printf("a[%2d]의 %2d를 b[%2d]에 저장.\n", i, a[i], f[a[i]]);
	}

	for (i = 0; i < n; i++) a[i] = b[i];
	puts("\n정렬 후의 배열");
	for (i = 0; i < n; i++) printf("%3d", i); putchar('\n');
	for (i = 0; i < n; i++) printf("%3d", a[i]); putchar('\n');
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
