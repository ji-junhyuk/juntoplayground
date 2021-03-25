#include <stdio.h>

int max3(int a, int b, int c)
{
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}

int main()
{
	printf("max3: %d", max3(100,200,300));
}
