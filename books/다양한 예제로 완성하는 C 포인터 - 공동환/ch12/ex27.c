#include <stdio.h>
#include <string.h>
typedef int (*ARR3)[3][3];
typedef int (*ARR9)[9];

void ArrPrint(ARR9 arr)
{
	int i, j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("%3d", arr[i][j]);
			j++;
		}
		puts("");
		i++;
	}
	puts("");
}

void main()
{
	int arr[9][9]; 
	ARR3 ap; // int (*ap)[3][3]; 
	int i, j;

	memset(arr, 0, sizeof(int)*9*9);
	ArrPrint(arr);

	ap = (ARR3)arr;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 3)
		{
			ap[i][1][j] = 1;
			j++;
		}
		i++;
	}
	ArrPrint(arr);

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 3)
		{
			ap[3][i][j] = 1;
			j++;
		}
		i++;
	}
	ArrPrint(arr);

	i = 3;
	while (i < 6)
	{
		j = 0;
		while (j < 3)
		{
			ap[i][1][j] = 3;
			j++;
		}
		i++;
	}
	ArrPrint(arr);
}
