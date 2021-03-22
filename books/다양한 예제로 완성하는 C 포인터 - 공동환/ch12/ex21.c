#include <stdio.h>
void main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	printf("%p %p\n", &arr[0], &arr[2]);
	printf("%ld\n", &arr[2] - &arr[0]);
	printf("%ld\n", &arr[0] - &arr[2]);
	printf("%p %p\n", &arr[5], &arr[0]);
	printf("%ld\n", &arr[5] - &arr[0]);
	printf("%ld\n", &arr[0] - &arr[5]);
}
