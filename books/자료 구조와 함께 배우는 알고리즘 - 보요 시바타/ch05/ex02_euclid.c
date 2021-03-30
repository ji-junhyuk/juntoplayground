#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	int x, y;
	printf("x, y: ");
	scanf("%d %d", &x, &y);
	printf("gcd: %d\n", gcd(x,y));

	return 0;
}
