#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i;
	int arr[100];

	srand((unsigned) time(NULL));

	i = 0;
	while (i < 100)
	{
		arr[i] = rand() % 100;
		i++;
	}

	i = 0;
	while (i < 100)
	{
		printf("%3d", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
		i++;
	}
}
