#include <stdio.h>
#include <string.h>
void main()
{
	int n = 10;

	memset(&n, 1, sizeof(int));
	printf("%d %x\n", n, n);

	memset(&n, 0xf, sizeof(int));
	printf("%d %x\n", n, n);

	memset(&n, 0xff, sizeof(int));
	printf("%d %x\n", n, n);
}
