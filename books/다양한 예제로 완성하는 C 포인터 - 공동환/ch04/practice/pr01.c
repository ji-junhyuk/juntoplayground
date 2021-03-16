#include <stdio.h>
int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int *ap = (int *)arr;
	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	printf("%d %d %d %d %d\n", ap[0], ap[1], ap[2], ap[3], ap[4]);
}
