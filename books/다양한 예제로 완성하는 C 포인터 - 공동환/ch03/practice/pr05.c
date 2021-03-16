#include <stdio.h>
int main()
{
	int arr[2][3] = {{1,2,3},{4,5,6}};
	printf("%p\n", arr);
	printf("%p %p %p\n", arr+1, arr[0]+1, arr[1]+1);
	printf("%p %p %p\n", arr+2, arr[0]+2, arr[1]+2);
	printf("%p %p %p\n", arr+3, arr[0]+3, arr[1]+3);
}
