#include <stdio.h>
void main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int *ap = arr;

	printf("%p %p\n", ap, arr);
	printf("%d %d\n", *ap, *arr);
//	printf("%d %d\n", *ap++, *arr++);
}
