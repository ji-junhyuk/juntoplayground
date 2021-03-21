#include <stdio.h>
void main()
{
	int a = 10, b = 20;
	
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	a ^= b;
	b ^= a;
	a ^= b;
	puts("=======");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
}
