#include <stdio.h>

int gcd(int x, int y)
{
	int temp;

	while (y)
	{
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;

}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("gcd: %d\n", gcd(x,y));

	return 0;
}
