#include <stdio.h>
int main()
{
	int iarr[5] = {10, 20, 30, 40, 50};

	printf("%p %p %p %p %p\n", iarr, iarr+1, iarr+2, iarr+3, iarr+4);
}
