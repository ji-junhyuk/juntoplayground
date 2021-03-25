#include <stdio.h>

int max4(int a, int b, int c, int d)
{
	int max = a;

	if (max < b)
		max = b;
	if (max < c)
		max = c;
	if (max <d)
		max = d;

	return max;
}

int main()
{
	printf("max4: %d", max4(400, 500, 600, 777));
}
