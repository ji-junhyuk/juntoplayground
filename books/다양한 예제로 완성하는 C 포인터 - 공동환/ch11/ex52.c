#include <stdio.h>
void main()
{
	int n = 0x44434241;

	printf("%x\n", (unsigned short)n);
	printf("%x\n", (unsigned int)n >> 16 && 0xFFFF);
}
