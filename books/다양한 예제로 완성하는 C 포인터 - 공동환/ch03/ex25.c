#include <stdio.h>
int main()
{
	int iarr2[2][2] = {1, 2, 3, 4};

	printf("%p\n", iarr2);
	printf("%p %p %p\n", iarr2[0], iarr2[1], &iarr2[0][0]);
}
