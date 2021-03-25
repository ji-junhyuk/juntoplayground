#include <stdio.h>
#include <stdlib.h>

double averageof(const int a[], int n)
{
	int i;
	double sum;

	i = 0;
	sum = 0;
	while (i < n)
	{
		sum += a[i];
		i++;
	}
	return sum/n;
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

	printf("Average: %g\n", averageof(height, number));
	free(height);

	return 0;
}
