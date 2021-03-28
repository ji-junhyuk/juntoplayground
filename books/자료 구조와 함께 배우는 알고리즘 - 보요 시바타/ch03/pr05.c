#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key)
		{
			while (pc > pl && a[pc-1] == key)
				pc++;
			return pc;
		}

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
	nx = 7;
	int x[] = {1, 3, 3, 3, 3, 4, 5};
	printf("key: ");
	ky = 3;
	idx = bin_search(x, nx, ky);
	if (idx == -1)
		puts("failed to search");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);

	return 0;
}
