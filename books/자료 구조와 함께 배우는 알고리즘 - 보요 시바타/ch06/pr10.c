#include <stdio.h>
#include <stdlib.h>

void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		int key = a[i];
		int pl = 0;
		int pr = i - 1;
		int pc;
		int pd;
		printf("do while 문 전, i값: %d, key값: %d, pl값: %d, pr값: %d\n)", i, key, pl, pr);
		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		printf("do while 문 후, i값: %d, key값: %d, pl값: %d, pr값: %d pc값:%d\n)", i, key, pl, pr,pc);

		pd = (pl <= pr) ? pc + 1 : pr + 1;
		printf("pd값: %d\n", pd);

		for (j = i; j > pd; j--)
			a[j] = a[j - 1];
		a[pd] = key;
	}
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

	bin_insertion(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
