#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int *a, const int *b)
{
	if (*a < *b)
		return 1;
	if (*a > *b)
		return -1;
	else 
		return 0;
}

int main()
{
	int i, nx, ky;
	int *x;
	int *p;

	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("x[0]: ");
	scanf("%d", &x[0]);

	i = 1;
	while (i < nx)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]);
		i++;
	}
	printf("key: ");
	scanf("%d", &ky);

	p = bsearch(&ky,
			x,
			nx,
			sizeof(int),
			(int(*)(const void *, const void *)) int_cmpr
			);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p-x));
	free(x);

	return 0;
}
