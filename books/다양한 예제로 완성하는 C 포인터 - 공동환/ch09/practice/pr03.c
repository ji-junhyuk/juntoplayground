#include <stdio.h>
void arrInput(int *arr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		arr[i] = 10*(i+1);
}

void arrOutput(int *arr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%5d ", arr[i]);
}

void main()
{
	int arr[10];
	void (*pfunc)(int *, int );

	pfunc = arrInput;
	pfunc(arr, 10);
	pfunc = arrOutput;
	pfunc(arr, 10);
}
