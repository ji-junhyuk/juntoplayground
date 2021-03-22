#include <stdio.h>
#include <string.h>

void main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int temp[10];
	int i;

	memcpy(temp, arr, sizeof(int) * 10);

	i = 0;
	while (i < 10)
	{
		printf("%d %d\n", arr[i], temp[i]);
		i++;
	}
	puts("");

	memcpy(temp, arr+5, sizeof(int)*5);
	memcpy(temp+5, arr, sizeof(int)*5);

	i = 0;
	while (i < 10)
	{
		printf("%d %d\n", arr[i], temp[i]);
		i++;
	}
}
