#include <stdio.h>

void main()
{
	int vector[] = {28,41,7};
	int *p0 = vector;
	int *p1 = vector+1;
	int *p2 = vector+2;

	printf("%d\n", p2>p0);
	printf("%d\n", p2<p0);
	printf("%d\n", p0>p1);
}
