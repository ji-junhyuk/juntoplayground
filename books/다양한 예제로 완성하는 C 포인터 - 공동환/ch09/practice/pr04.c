#include <stdio.h>
void main()
{
	int n1=10, n2=20, n3=30;

	int *arr[3];
	arr[0] = &n1;
	arr[1] = &n2;
	arr[2] = &n3;

	printf("%d %d %d\n", *arr[0], *arr[1], *arr[2]);
}
