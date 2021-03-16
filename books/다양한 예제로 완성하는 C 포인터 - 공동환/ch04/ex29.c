#include <stdio.h>
int main()
{
	int iarr[4] = {0x1011, 0x2022, 0x3033, 0x4044};
	char *ap = (char *)iarr;

	printf("%p %p %p %p\n", iarr, iarr+1, iarr+2, iarr+3);
	printf("%p %p %p %p\n", ap, ap+4, ap+8, ap+12);
}
