#include <stdio.h>
typedef union
{
	struct 
	{
		unsigned char b1; unsigned char b2;
		unsigned char b3; unsigned char b4;
	} byte;
	struct 
	{
		unsigned short w1; unsigned short w2;
	} word;
	unsigned long dword;
} UBYTE4;

void main()
{
	UBYTE4 data;

	data.dword = 0x44434241;

	printf("%lx\n", data.dword);
	printf("%x%x\n", data.word.w2, data.word.w1);
	printf("%x%x%x%x\n", data.byte.b4, data.byte.b3, data.byte.b2, data.byte.b1);

	puts("");
	data.byte.b1 = 0x11;
	data.byte.b2 = 0x22;
	data.byte.b3 = 0x33;
	data.byte.b4 = 0x44;

	printf("%lx\n", data.dword);
	printf("%x%x\n", data.word.w2, data.word.w1);
	printf("%x%x%x%x\n", data.byte.b4, data.byte.b3, data.byte.b2, data.byte.b1);
	puts("");

	printf("%ld %ld\n", sizeof(UBYTE4), sizeof(data));
	printf("%ld %ld\n", sizeof(data.word.w1), sizeof(data.word.w2));
	printf("%ld %ld\n", sizeof(data.byte.b1), sizeof(data.byte.b2));
}
