#include <stdio.h>

int med(int a, int b, int c)
{
	if (a > b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else 
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else 
		return b;
}

int main(void)
{
	printf("med: %d\n", med(100,200,300));
	printf("med: %d\n", med(200,200,300));
	printf("med: %d\n", med(300,200,300));
}
