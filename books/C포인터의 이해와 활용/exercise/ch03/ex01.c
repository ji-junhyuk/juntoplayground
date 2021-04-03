#include <stdio.h>
void average(int *arr, int size)
{
	int sum;

	printf("arr: %p\n", &arr);
	printf("size: %p\n", &size);
	printf("sum: %p\n", &sum);
	int i = 0;
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
}

int main(void)
{
	int *a;
	int size = 5;
	average(a, 5);
	return 0;
}
