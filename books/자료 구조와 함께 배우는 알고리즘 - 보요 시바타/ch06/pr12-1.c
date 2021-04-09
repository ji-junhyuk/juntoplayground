#include <stdio.h>
#include <stdlib.h>

int shell(int a[], int n)
{
	int i, j, h;
	int count = 0;

	for (h = n / 2; h > 0; h/=2)
		for (i = h; i < n; i++)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j-=h)
			{
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	return count;
}

int main()
{
	int i, nx;
	int *x;
	int count;

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

	count = shell(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	printf("요소의 이동 횟수: %d\n", count);

	free(x);

	return 0;
}
