#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n)
{
	int i, sum;

	i = 0;
	sum = 0;
	while (i < n)
	{
		sum += a[i];
		i++;
	}
	return sum;
}

int main()
{
	int i, number;
	int *height;
	scanf("%d", &number);

	height = calloc(number, sizeof(int));

	i = 0;
	while (i < number)
	{
		printf("height[%d]: ", i);
		scanf("%d", &height[i]);
		i++;
	}

	printf("Sum: %d\n", sumof(height, number));
	free(height);

	return 0;
}
