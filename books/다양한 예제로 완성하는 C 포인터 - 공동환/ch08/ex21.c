#include <stdio.h>
void func(int *ap)
{
	printf("%d %d %d %d %d\n", ap[0], ap[1], ap[2], ap[3], ap[4]);
}

void main()
{
	int iarr[5] = {1, 2, 3, 4, 5};

	func(iarr);
}
