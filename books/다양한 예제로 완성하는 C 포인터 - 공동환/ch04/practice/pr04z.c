#include <stdio.h>
int main()
{
	int arr[2][3] = {{10, 20, 30}, {100, 200, 300}};
	int (*ap) = (int *)arr;

	printf("%d %d %d %d %d %d\n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2]);
	printf("%d %d %d %d %d %d\n", ap[0], ap[1], ap[2], ap[3], ap[4], ap[5]);
}
