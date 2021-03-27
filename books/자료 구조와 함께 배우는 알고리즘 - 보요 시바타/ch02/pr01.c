#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n)
{
	int i;
	int min = a[0];

	i = 1;
	while (i < n)
	{
		if (a[i] < min) 
			min = a[i];
		i++;
	}
	return min;
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

	printf("Min: %d\n", minof(height, number));
	free(height);

	return 0;
}
