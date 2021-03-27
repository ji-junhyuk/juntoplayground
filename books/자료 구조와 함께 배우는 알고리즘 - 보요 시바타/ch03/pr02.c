#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key)
			return pc;
		else if (a[pc] > key)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);

	return -1;
}

int main()
{
	int i, j, nx, ky, idx;
	int *x;
	srand(time(NULL));
	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
			x[i] = 1 + rand() % 6;
			
			j = i + 1;
			while (j < nx)
			{
				if (x[i] == x[j])
				{
					x[j] == rand() % 6;
					i = 0;
				}
				j++;
			}
			i++;
	}
	ky = rand() % 6;
	printf("key: %d\n", ky);
	
	i = 0;
	while (i < nx)
	{
		printf("%d ", x[i]);
		i++;
	}
	puts("");

	idx = bin_search(x, nx, ky);
	if (idx == -1)
		puts("failed to search");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);
	free(x);

	return 0;
}
