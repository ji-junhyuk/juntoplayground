#include <stdio.h>
int main()
{
	int iarr[4] = {1,2,3,4};
	int (*ap)[2] = (int(*)[2]) iarr;

	printf("%ld %ld\n", sizeof(iarr), sizeof(ap));
	printf("%p %p\n", iarr, ap);
	printf("%p %p\n", ap, ap[0]);
	printf("%p %p\n", ap+1, ap[0]+1);
}
