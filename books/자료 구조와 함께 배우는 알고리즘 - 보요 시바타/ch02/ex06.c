#include <stdio.h>
#include <time.h>
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
	srand(time(NULL));

	i = 0;
	while (i < number)
	{
		height[i] = 100 + rand() % 100;
		printf("height[%d] = %d\n", i, height[i]);
		i++;
	}
	printf("max: %d", maxof(height, number));

	free(height);

	return 0;
}
