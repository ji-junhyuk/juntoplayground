#include <stdio.h>
int main()
{
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int *iarr[5] = {&a, &b, &c, &d, &e};

	printf("%ld %ld %ld\n", sizeof(iarr), sizeof(iarr[0]), sizeof(*iarr[0]));
}
