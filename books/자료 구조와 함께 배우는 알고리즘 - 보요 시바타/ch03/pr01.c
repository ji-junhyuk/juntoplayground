#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
	int i;

	a[n] = key;
	for (i = 0; i < n; i++)
		if (a[i] == key)
			break;
	return i == n ? -1 : i;
}

int main()
{
	int i, nx, ky, idx;
	int *x;
	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx+1, sizeof(int));

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
