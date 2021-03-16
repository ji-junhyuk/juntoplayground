#include <stdio.h>
int main()
{
	int iarr[4] = {1,2,3,4};
	int *ip = iarr;

	printf("%ld %ld\n", sizeof(iarr), sizeof(ip));
}
