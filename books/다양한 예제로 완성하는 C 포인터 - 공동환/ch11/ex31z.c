#include <stdio.h>
#include <stdlib.h>

void main()
{
	int arr[100];
	int numCount[10] = {0};
	int i;

	i = 0;
	while (i < 100)
	{
		arr[i++] = rand() % 100;
	}

	i = 0;
	while (i < 100)
	{
		printf("%3d", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
		i++;
	}

	i = 0;
	while (i < 100)
	{
		numCount[arr[i]/10]++;
		i++;
	}

	i = 0;
	while (i < 10)
	{
		printf("%d ~ %d : %d\n", i*10, (i+1)*10-1, numCount[i]);
		i++;
	}
}		
