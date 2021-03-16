#include <stdio.h>
int main()
{
	int arr[5] = {1,2,3,4,5};

	printf("%p\n", arr);
	puts("====================");
	printf("%p %p\n", arr, &arr[0]);
	printf("%p %p\n", arr+1, &arr[1]);
	printf("%p %p\n", arr+2, &arr[2]);
	printf("%p %p\n", arr+3, &arr[3]);
	printf("%p %p\n", arr+4, &arr[4]);
}
