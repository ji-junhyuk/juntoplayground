#include <stdio.h>
#include <string.h>
void main()
{
	int arr1[25];
	int arr2[5][5];
	int i, j;

	i = 0;
	while (i < 25)
	{
		arr1[i] = (i+1) * 10;
		i++;
	}
	memcpy(arr2, arr1, sizeof(int)*25);

	i = 0;
	while (i < 25)
	{
		printf("%5d", arr1[i]);
		if ((i+1) % 5 == 0)
			puts("");
		i++;
	}
	puts("");
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("%5d", arr2[i][j]);
			j++;
		}
		i++;
		puts("");
	}
}
