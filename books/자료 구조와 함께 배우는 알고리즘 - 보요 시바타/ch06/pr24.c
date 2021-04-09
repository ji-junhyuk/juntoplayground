#include <stdio.h>
#include <stdlib.h>

void fsort2(int a[], int n, int min, int max)
{
	int i;
	int *f = calloc(max + 1, sizeof(int));
	int *b = calloc(n, sizeof(int));

	for (i = 0; i <= max - min + 1; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i] - min]++;
	for (i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

int main()
{
	int i, nx;
	int *x;
	int min, max;
	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("min: ");
	scanf("%d", &min);

	while (1)
	{
		printf("max: ");
		scanf("%d", &max);
		if (max > min) break;
		printf("%d보다 큰 값을 입력하세요.\n", min);
	}

	printf("%d ~ %d의 정수를 입력하세요.\n", min, max);
	for (i = 0; i < nx; i++)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < min || x[i] > max);
	}

	fsort2(x, nx, min, max);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
