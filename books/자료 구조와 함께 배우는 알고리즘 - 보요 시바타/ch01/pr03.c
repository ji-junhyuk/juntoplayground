#include <stdio.h>
int min4(int a, int b, int c, int d)
{
	int min = a;

	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;

	return min;
}

void main()
{
	printf("%d\n", min4(1,2,3,0));
}
