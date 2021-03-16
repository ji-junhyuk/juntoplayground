#include <stdio.h>
int main()
{
	int iarr[6] = {1,2,3,4,5,6};
	printf("%p\n", iarr);
	printf("%d %d %d %d %d %d\n", iarr[0], iarr[1], iarr[2], iarr[3], iarr[4], iarr[5]);
	printf("%d %d %d %d %d %d\n", *iarr, *(iarr+1), *(iarr+2), *(iarr+3), *(iarr+4), *(iarr+5));
}
