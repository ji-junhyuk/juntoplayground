#include <stdio.h>
void main()
{
	short n = 0x4241;

	printf("%x\n", (unsigned char)n);
	printf("%x\n", (unsigned short)n >> 8 & 0xFF);
}
