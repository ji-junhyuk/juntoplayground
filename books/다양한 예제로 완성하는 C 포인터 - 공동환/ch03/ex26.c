#include <stdio.h>
int main()
{
	int iarr3[2][3][2] = {1,2,3,4,5,6,7,8,9,10,11,12};

	printf("%p\n", iarr3);
	printf("%p %p\n", iarr3[0], iarr3[1]);
	printf("%p %p %p %p\n", iarr3[0][0], iarr3[0][1], iarr3[1][0], iarr3[1][1]);
	printf("%p %p %p %p\n", &iarr3[0][0][0], &iarr3[0][1][0], &iarr3[1][0][0], &iarr3[1][1][0]);
	printf("%d %d %d %d\n", iarr3[0][0][0], iarr3[0][1][0], iarr3[1][0][0], iarr3[1][1][0]);
}
