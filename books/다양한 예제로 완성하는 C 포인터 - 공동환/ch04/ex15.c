#include <stdio.h>
int main()
{
	int iarr2[2][2] = {1,2,3,4};
	int (*ap)[2] = iarr2;

	printf("%d %d %d %d\n", iarr2[0][0], iarr2[0][1], iarr2[1][0], iarr2[1][1]);
	printf("%d %d %d %d\n", ap[0][0], ap[0][1], ap[1][0], ap[1][1]);
}
