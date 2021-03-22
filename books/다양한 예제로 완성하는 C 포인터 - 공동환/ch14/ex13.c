#include <stdio.h>
#include <string.h>
typedef struct _bitfield
{
	unsigned b0:1;
	unsigned    :7;
	unsigned b8:1;
	unsigned    :7;
	unsigned b16:1;
	unsigned    :7;
	unsigned b24:1;
} BITFIELD;
void main ( )
{
	BITFIELD bit;

	memset(&bit, 0, sizeof(BITFIELD));
	bit.b0 = 1;
	bit.b8 = 1;
	bit.b16 = 1;
	bit.b24 = 1;

	printf("%d\n", sizeof(bit));
	printf("%08x %d\n", bit, bit);
} 			
