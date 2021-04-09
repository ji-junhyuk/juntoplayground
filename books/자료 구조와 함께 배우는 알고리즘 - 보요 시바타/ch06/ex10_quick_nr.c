#include <stdio.h>
#include <stdlib.h>
#include "../ch04/ex01_IntStack.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void quick(int a[], int left, int right)
{
	IntStack lstack;
	IntStack rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack))
	{
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];
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
		printf("left: %d pr: %d, pl: %d right: %d\n", left, pr, pl, right);

		if (left < pr)
		{
			Push(&lstack, left);
			Push(&rstack, pr);
		}
		if (right > pl)
		{
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
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
