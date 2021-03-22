#include <stdio.h>
#include <string.h>
void main()
{
	int n = 10;

	memset(&n, 0, sizeof(int));
	printf("%d %x\n", n, n);
}
