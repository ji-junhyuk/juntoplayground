#include <stdio.h>
void func(int *arr1, int arr2[2][3])
{
	printf("%d %d %d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5]);
	printf("%d %d %d %d %d %d\n", arr2[0][0], arr2[0][1], arr2[0][2], arr2[1][0], arr2[1][1], arr2[1][2]);
}

void main()
{
	int arr1[6] = {10, 20, 30, 40, 50, 60};
	int arr2[2][3] = {{100, 200, 300}, {400, 500, 600}};
	func(arr1, arr2);
}
