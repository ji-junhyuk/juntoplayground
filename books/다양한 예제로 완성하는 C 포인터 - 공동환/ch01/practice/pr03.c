#include <stdio.h>
int main()
{
	char c = 'A';
	int n = 10;
	long l = 10l;
	float f = 5.25f;
	double d = 5.25;

	printf("%p\n", &c);
	printf("%p\n", &n);
	printf("%p\n", &l);
	printf("%p\n", &f);
	printf("%p\n", &d);
	puts("==============");
	printf("%p\n", &c + 1);
	printf("%p\n", &n + 1);
	printf("%p\n", &l + 1);
	printf("%p\n", &f + 1);
	printf("%p\n", &d + 1);
}
