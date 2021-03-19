#include <stdio.h>
void main()
{
	int arr3[2][2][3] = {{{1,2,3}, {4,5,6}}, {{7,8,9}, {10,11,12}}};
	int (*arr)[2][3];

	arr = arr3;

	printf("%d %d %d\n", arr[0][0][0], arr[0][0][1], arr[0][0][2]);
	printf("%d %d %d\n", arr[0][1][0], arr[0][1][1], arr[0][1][2]);
	printf("%d %d %d\n", arr[1][0][0], arr[1][0][1], arr[1][0][2]);
	printf("%d %d %d\n", arr[1][1][0], arr[1][1][1], arr[1][1][2]);
}
