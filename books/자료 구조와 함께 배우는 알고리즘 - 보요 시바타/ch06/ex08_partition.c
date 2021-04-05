#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void partition(int a[], int n)
{
	int i;
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];
	do {
		while(a[pl] < x) pl++;
		while(a[pr] > x) pr++;
		if (pl <= pr)
		{
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	puts("피벗이하의 그룹");
	for (i = 0; i <=pl - 1; i++)
		printf("%d ", a[i]);
	puts("");
	if (pl > pr + 1)
	{
		puts("피벗과 일치하는 그룹");
		for (i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		puts("");
	}
	printf("피벗 이상의 그룹\n");
	for (i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
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

	partition(x, nx);

	free(x);

	return 0;
}
