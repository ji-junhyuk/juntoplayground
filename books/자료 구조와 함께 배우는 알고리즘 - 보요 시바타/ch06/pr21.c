#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buff;

void __mergesort(char *a, size_t left, size_t right, size_t size, int(*compar)(const void *, const void *))
{
	if (left < right)
	{
		size_t center = (left + right) / 2;
		size_t p = 0;
		size_t i;
		size_t j = 0;
		size_t k = left;

		__mergesort(a, left, center, size, compar);
		__mergesort(a, center+1, right, size, compar);

		for (i = left; i <= center; i++)
			memcpy(&buff[p++ * size], &a[i * size], size);

		while (i <= right && j < p)
			memcpy(&a[k++ * size], compar((const void *)&buff[j * size], (const void *)&a[i * size]) <= 0 ?
					&buff[j++ * size] : &a[i++ * size], size);

		while (j < p)
			memcpy(&a[k++ * size], &buff[j++ * size], size);
	}
}

void m_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	if (nmemb > 0)
	{
		buff = calloc(nmemb, size);

		__mergesort(base, 0, nmemb - 1, size, compar);

		free(buff);
	}
}

int int_cmp(const int *a, const int *b)
{
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main()
{
	int i, nx;
	int *x;
	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	
	m_sort(x, 
			nx, 
			sizeof(int),
			(int(*)(const void *, const void *))int_cmp
		  );
	
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
