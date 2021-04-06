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

	printf("a[%d] ~ a[%d]를 스택에 푸쉬합니다.\n", left, right);
	printf("lstack: "); Print(&lstack);
	printf("rstack: "); Print(&rstack);

	while (!IsEmpty(&lstack))
	{
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		puts("====================");
		printf("스택에서 꺼낸 배열의 범위는 a[%d] ~ a[%d]입니다.\n", left, right);
		puts("====================");

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

		if (left < pr)
		{
			Push(&lstack, left);
			Push(&rstack, pr);

			printf("a[%d] ~ a[%d]를 스택에 푸쉬합니다.\n", left, pr);
			printf("lstack: "); Print(&lstack);
			printf("rstack: "); Print(&rstack);
		}
		if (right > pl)
		{
			Push(&lstack, pl);
			Push(&rstack, right);

			printf("a[%d] ~ a[%d]를 스택에 푸쉬합니다.\n", pl, right);
			printf("lstack: "); Print(&lstack);
			printf("rstack: "); Print(&rstack);
		}
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
