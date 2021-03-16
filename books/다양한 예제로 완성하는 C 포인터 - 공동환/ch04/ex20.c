#include <stdio.h>
int main()
{
	int iarr2[2][2] = {1,2,3,4};
	int *ap = (int *)iarr2;

	printf("%ld %ld\n", sizeof(iarr2), sizeof(ap));
}
