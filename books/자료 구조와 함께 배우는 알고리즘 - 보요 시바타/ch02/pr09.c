#include <stdio.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void ary_rcopy(int a[], const int b[], int n)
{
	int i, j;

	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';

	j = 0;
	while (j < n/2)
	{
		swap(int, a[j], a[i - j - 1]);
		j++;
	}
}

int main(void)
{
	int i;
	int arrA[] = {1,2,3,4,5};
	int arrB[50];

	ary_rcopy(arrB, arrA, 3);

	i = 0;
	while (i < 4)
	{
		printf("arrB[%d]: %d\n", i, arrB[i]);
		i++;
	}

	return 0;
}
