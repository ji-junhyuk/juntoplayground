#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
	int i, j;

	printf("   |");
	for (i = 0; i < n; i++)
		printf("%3d", i);

	printf("\n---+---------------");
	puts("");

	i = 0;
	while (i < n)
	{
		printf("   |");
		printf("%*s",3*(i-1)+5,"");
		printf("*\n");
		printf("%3d|", i);
		j = 0;
		while (j < n)
		{
			printf("%3d", a[j]);
			j++;
		}
		puts("");
		if (a[i] == key)
			return i;
		i++;
	}
	return -1;
}

int main()
{
	int i, nx, ky, idx;
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
	printf("key: ");
	scanf("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("failed to search");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);
	free(x);

	return 0;
}
