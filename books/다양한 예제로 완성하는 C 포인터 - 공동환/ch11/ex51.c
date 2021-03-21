#include <stdio.h>
#define LOBYTE(x) ((unsigned char)x)
#define HIBYTE(x) ((unsigned short)x >> 8 & 0xFF)
void main()
{
	int n = 0x4241;

	printf("%x\n", LOBYTE(n));
	printf("%x\n", HIBYTE(n));
}
