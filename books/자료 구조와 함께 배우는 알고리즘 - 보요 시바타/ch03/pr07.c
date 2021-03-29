#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, 
		int (*compar)(const void *, const void *))
{
	size_t i;
	char *x = (char *)base;

	i = 0;
	while (i < nmemb)
	{
		if (!compar((const void *)&x[i * size], key))
			return (&x[i * size]);
		i++;
	}
	return NULL;
}

int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
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
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		i++;
	}
	printf("key: ");
	scanf("%d", &ky);

	p = seqsearch(&ky,
			x,
			nx,
			sizeof(int),
			(int(*)(const void *, const void *)) int_cmp
			);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p-x));
	free(x);

	return 0;
}
