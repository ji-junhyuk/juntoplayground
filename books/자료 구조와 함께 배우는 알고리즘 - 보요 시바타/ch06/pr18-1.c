#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
int sort3elem(int x[], int a, int b, int c)
{
	if (x[b] < x[a]) swap(int, x[b], x[a]);
	if (x[c] < x[b]) swap(int, x[c], x[b]);
	if (x[b] < x[a]) swap(int, x[b], x[a]);
	return b;
}

void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

void quick(int a[], int left, int right)
{
	if (right - left < 9)
		insertion(&a[left], right - left + 1);
	else
	{
		int pl = left;
		int pr = right;
		int x;
		int m = sort3elem(a, pl, (pl + pr) / 2, pr);
		x = a[m];
		swap(int, a[m], a[right - 1]);
		pl++;
		pr -= 2;


		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr)
			{
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (pr - left < right - pl)
		{
			swap(int, pl, left);
			swap(int, pr, right);
		}
		if (left < pr) quick(a, left, pr);
		if (right > pl) quick(a, pl, right);
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
	quick(x, 0, nx - 1);
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}
