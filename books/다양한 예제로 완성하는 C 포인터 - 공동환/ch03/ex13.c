#include <stdio.h>
int main()
{
	int iarr1[9] = {1,2,3,4,5,6,7,8,9};
	int iarr2[3][3] = {1,2,3,4,5,6,7,8,9};

	printf("%d %d %d %d %d %d %d %d %d\n", iarr1[0], iarr1[1], iarr1[2], iarr1[3], iarr1[4], iarr1[5], iarr1[6], iarr1[7], iarr1[8]);
	printf("%d %d %d %d \n", iarr2[0][0], iarr2[1][0], iarr2[2][0], iarr2[2][2]);
}
