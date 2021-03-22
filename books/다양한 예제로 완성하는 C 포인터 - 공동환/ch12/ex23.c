#include <stdio.h>
void main()
{
	int iarr[2][3] = {{1,2,3}, {10,20,30}};

	printf("%p %p %p\n", iarr, iarr[0], &iarr[0][0]);
	printf("%p %p %p\n", iarr+1, iarr[0]+1, &iarr[0][0]+1);
}


