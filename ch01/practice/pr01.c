#include <stdio.h>
int main()
{
	char c = 'A';
	int n = 10;
	long l = 10l;
	float f = 5.25f;
	double d = 5.25;

	printf("%ld\n", sizeof(c));
	printf("%ld\n", sizeof(n));
	printf("%ld\n", sizeof(l));
	printf("%ld\n", sizeof(f));
	printf("%ld\n", sizeof(d));
	puts("================");
	printf("%ld\n", sizeof(&c));
	printf("%ld\n", sizeof(&n));
	printf("%ld\n", sizeof(&l));
	printf("%ld\n", sizeof(&f));
	printf("%ld\n", sizeof(&d));
}
