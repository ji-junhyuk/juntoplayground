#include <stdio.h>
#include <string.h>
struct _bitfield
{
	unsigned b0:1;
	unsigned b1:1;
	unsigned b2:1;
	unsigned b3:1;
	unsigned b4:1;
	unsigned b5:1;
	unsigned b6:1;
	unsigned b7:1;
};

void main()
{
	struct _bitfield bit;

	memset(&bit, 0, sizeof(struct _bitfield));
	bit.b0 = 1;
	bit.b7 = 1;

	printf("%ld\n", sizeof(struct _bitfield));
	printf("%x %d\n", bit, bit);
}
