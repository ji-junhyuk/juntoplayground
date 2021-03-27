#include <stdio.h>
void ary_copy(int a[], const int b[], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}

int main(void)
{
	int i;
	int arrA[] = {1,2,3,4,5};
	int arrB[50];

	ary_copy(arrB, arrA, 3);

	i = 0;
	while (i < 4)
	{
		printf("arrB[%d]: %d\n", i, arrB[i]);
		i++;
	}

	return 0;
}
