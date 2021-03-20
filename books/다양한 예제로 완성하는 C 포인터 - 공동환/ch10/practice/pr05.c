#include <stdio.h>
void arrPrint(const int *const arr)
{
	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//	arr[0] = 100;
//	arr = &arr[4];	
}

void main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	arrPrint(arr);
}
