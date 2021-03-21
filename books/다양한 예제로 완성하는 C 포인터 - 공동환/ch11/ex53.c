#include <stdio.h>
#define LOWORD(x) ((unsigned short)x)
#define HIWORD(x) ((unsigned int)x >> 16 & 0xFFFF)
void main()
{
	int n = 0x44434241;

	printf("%x\n", LOWORD(n));
	printf("%x\n", HIWORD(n));
}
