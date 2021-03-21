#include <stdio.h>
 //void swap(int *a, int *b)
 //{
 //	*a ^= *b;
 //	*b ^= *a;
 //	*a ^= *b;
 //}
 //
 //void main()
 //{
 //	int a = 10, b = 20;
 //
 //	printf("%d %d\n", a, b);
 //
 //	swap(&a, &b);
 //	printf("%d %d\n", a, b);
 //}
#define SWAP(a, b) {a^=b; b^=a; a^=b;}
void main()
{
	int a = 10, b = 20;

	SWAP(a,b);
	printf("%d %d\n", a, b);
}
