#include <stdio.h>
int main()
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int (*ap)[2] = (int (*)[2]) arr;

	printf("%d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	printf("%d %d %d %d %d %d\n", ap[0][0], ap[0][1], ap[1][0], ap[1][1], ap[2][0], ap[2][1]);
}
