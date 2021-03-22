#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int arr[10];
	int i;

	i = 0;
	while (i < 10)
	{
		arr[i] = rand()%100;
		printf("%5d", arr[i++]);
	}
	puts("");

	memset(arr, 0, sizeof(int)*10);
	
	i = 0;
	while (i < 10)
		printf("%5d", arr[i++]);
}
