#include <stdio.h>
int min3(int a, int b, int c)
{
	int min = a;

	if (min > b)
		min = b;
	if (min > c)
		min = c;

	return min;
}

void main(void)
{
	printf("min3: %d\n", min3(500, 400, 300));
}
