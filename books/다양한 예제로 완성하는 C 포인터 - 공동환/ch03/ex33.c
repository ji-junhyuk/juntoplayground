#include <stdio.h>
int main()
{
	int iarr2[2][3] = {1,2,3,4,5,6};

	printf("%d\n", ((int (*)[3])0x12ff68)[0][0]);
}
