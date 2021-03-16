#include <stdio.h>
int main()
{
	int iarr[4] = {1,2,3,4};
	int (*ap)[2] = (int(*)[2])iarr;

	printf("%d %d %d %d\n", iarr[0], iarr[1], iarr[2], iarr[3]);
	printf("%d %d %d %d\n", ap[0][0], ap[0][1], ap[1][0], ap[1][1]);
}
