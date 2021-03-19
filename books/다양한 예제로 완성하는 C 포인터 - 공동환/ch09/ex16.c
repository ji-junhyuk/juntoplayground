#include <stdio.h>
void main()
{
	int n1 = 10;
	int n2 = 20;
	int n3 = 30;
	int *arr[3] = {&n1, &n2, &n3};

	printf("%d %d %d\n", n1, n2, n3);
	printf("%d %d %d\n", *arr[0], *arr[1], *arr[2]);
}
