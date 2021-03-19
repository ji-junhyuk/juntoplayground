#include <stdio.h>
void main()
{
	int n1 = 10, n2 = 20, n3 = 30, n4 = 40, n5 = 50, n6 = 60, n7 = 70, n8 = 80, n9 = 90;
	int *iarr1[2][3] = {{&n1, &n2, &n3}, {&n4, &n5, &n6}};
	int *iarr2[3][3] = {{&n1, &n2, &n3}, {&n4, &n5, &n6}, {&n7, &n8, &n9}};

	int *(*arr)[3];
	printf("%d %d %d %d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6, n7, n8, n9);

	arr = iarr1;

	printf("%d %d %d\n", *arr[0][0], *arr[1][0], *arr[1][2]);

	arr = iarr2;
	printf("%d %d %d %d\n", *arr[0][0], *arr[1][0], *arr[2][0], *arr[2][2]);
}
