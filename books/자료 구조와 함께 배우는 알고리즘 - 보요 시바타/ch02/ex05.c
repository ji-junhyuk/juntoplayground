#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int i;
	int max = a[0];

	i = 1;
	while (i < n)
	{
		if (a[i] > max) 
			max = a[i];
		i++;
	}
	return max;
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

	printf("Max: %d\n", maxof(height, number));
	free(height);

	return 0;
}
