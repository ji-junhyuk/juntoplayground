#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	int i;

	printf("   |");
	for (i = 0; i < n; i++)
		printf("%4d", i);
	
	printf("\n---+");
	i = 0;
	while (i < n)
	{
		printf("----");
		i++;
	}
	puts("");

	do {
		pc = (pl + pr) / 2;
		printf("   |");

		for (i = 0; i < 4 * pl; i++) printf(" ");
		printf("<-");
		for (i = 0; i < 4 * (pc - pl); i++) printf("b");
		printf("+");
		for (i = 0; i < 4 * (pr - pc)-2; i++) printf("c");
		printf("->\n");

		printf("%3d|", pc);
		for (i = 0; i < n; i++)
			printf("%4d", a[i]);
		puts("");

		printf("pr:%d pl:%d pc:%d\n", pr, pl, pc);
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
	idx = bin_search(x, nx, ky);
	if (idx == -1)
		puts("failed to search");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);
	free(x);

	return 0;
}
