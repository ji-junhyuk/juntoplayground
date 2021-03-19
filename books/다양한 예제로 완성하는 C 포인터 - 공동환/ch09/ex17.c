#include <stdio.h>
void main()
{
	int arr2[2][3] = {{1,2,3}, {4,5,6}};
	int (*arr)[3];

	arr = arr2;

	printf("%d %d %d %d %d %d\n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2]);
}
