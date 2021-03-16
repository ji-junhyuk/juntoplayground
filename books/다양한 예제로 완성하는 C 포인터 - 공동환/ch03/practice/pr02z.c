#include <stdio.h>
int main()
{
	int arr[5] = {1,2,3,4,5};
	printf("%ld %ld %ld\n", sizeof(arr), sizeof(arr[0]), sizeof(&arr[0]));
}
