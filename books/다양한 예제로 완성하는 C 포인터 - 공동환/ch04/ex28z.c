#include <stdio.h>
int main()
{
	int iarr[5] = {300,310,320,330};
	char *ap = (char *)iarr;

	printf("%d %d %d %d\n", iarr[0], iarr[1], iarr[2], iarr[3]);
	printf("%d %d %d %d\n", ap[0], ap[1], ap[2], ap[3]);
	printf("%d %d %d %d\n", ap[4], ap[5], ap[6], ap[7]);
	printf("%d %d %d %d\n", ap[8], ap[9], ap[10], ap[11]);
	printf("%d %d %d %d\n", ap[12], ap[13], ap[14], ap[15]);
}
