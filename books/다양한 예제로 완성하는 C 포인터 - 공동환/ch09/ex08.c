#include <stdio.h>
void fplus(int n1, int n2)
{
	printf("%d + %d = %d\n", n1, n2, n1+n2);
}

void fminus(int n1, int n2)
{
	printf("%d - %d = %d\n", n1, n2, n1-n2);
}

void main()
{
	void (*fp)(int, int);

	fp = fplus;
	fp(10, 10);

	fp = fminus;
	fp(5, 5);
}
