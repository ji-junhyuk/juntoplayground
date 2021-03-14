#include <stdio.h>
int main()
{
	int n;
	*((char*)&n) = 4;
	*((char*)&n+1) = 3;
	*((char*)&n+2) = 2;
	*((char*)&n+3) = 1;
	printf("%08x %d\n", n, n);
}
