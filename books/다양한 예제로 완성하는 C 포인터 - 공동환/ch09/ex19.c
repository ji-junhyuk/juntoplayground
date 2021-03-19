#include <stdio.h>
void main()
{
	int iarr1[2][3] = {{1,2,3},{4,5,6}};
	int iarr2[3][3] = {{11,12,13},{14,15,16},{17,18,19}};
	int (*arr[2])[3];

	arr[0] = iarr1;
	arr[1] = iarr2;

	printf("%d %d %d\n", arr[0][0][1], arr[0][1][1], arr[0][1][2]);
	printf("%d %d %d\n", arr[1][0][1], arr[1][1][1], arr[1][2][2]);
}
