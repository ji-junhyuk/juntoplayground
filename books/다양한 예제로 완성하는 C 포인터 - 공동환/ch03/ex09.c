#include <stdio.h>
int main()
{
	int iarr[5] = {10, 20, 30, 40, 50};
	printf("%d %d %d %d %d\n", iarr[0], iarr[1], iarr[2], iarr[3], iarr[4]);
	printf("%d %d %d %d %d\n", *(iarr+0), *(iarr+1), *(iarr+2), *(iarr+3), *(iarr+4));
	printf("%d %d %d %d %d\n", *&iarr[0], *&iarr[1], *&iarr[2], *&iarr[3], *&iarr[4]);
}
