#include <stdio.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

#define MAKEWORD(x, y) ((BYTE)x | (WORD)y << 8)
#define MAKEDWORD(x, y) ((WORD)x | (DWORD)y << 8)

void main()
{
	int n = 0;

	n = MAKEDWORD(MAKEWORD(0x41, 0x42), MAKEWORD(0x43,0x44));
	printf("%x\n", n);
}
