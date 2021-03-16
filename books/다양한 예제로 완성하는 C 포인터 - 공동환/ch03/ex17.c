#include <stdio.h>
int main()
{
	int iarr2[3][3] = {1,2,3,4,5,6,7,8,9};
	printf("%p\n", iarr2);
	printf("%p %p %p\n", iarr2[0], iarr2[1], iarr2[2]);
}
