#include <stdio.h>
void main()
{
	int n = 1;

	printf ("%x %d\n", n << 0, n << 0);
	printf ("%x %d\n", n << 1, n << 1);
	printf ("%x %d\n", n << 2, n << 2);
	printf ("%x %d\n", n << 3, n << 3);
	printf ("%x %d\n", n << 4, n << 4);
}
