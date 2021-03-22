#include <stdio.h>
#include <string.h>
void main()
{
	int arr[25];
	int (*ap)[5] = (int (*)[5])arr;
	int i, j;

	i = 0;
	while (i < 25)
	{
		arr[i] = (i+1)*10;
		i++;
	}

	i = 0;
	while (i < 5)
	{
		ap[i][i] = 0;
		i++;
	}

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("%5d", ap[i][j]);
			j++;
		}
		puts("");
		i++;
	}

	i = 0;
	while (i < 25)
	{
		printf("%5d", arr[i]);
		if ((i + 1) % 5 == 0)
			puts("");
		i++;
	}
}
