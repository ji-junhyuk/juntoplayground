#include <stdio.h>

int sumof(int a, int b)
{
	int min, max, sum;

	if (a >= b)
	{
		min = b;
		max = a;
	}
	else 
	{
		min = a;
		max = b;
	}

	sum = 0;
	while (min <= max)
	{
		sum += min;
		min++;
	}

	return sum;
}

void main()
{
	printf("sumof(1,2): %d\n", sumof(1,2));
	printf("sumof(2,2): %d\n", sumof(2,2));
	printf("sumof(2,8): %d\n", sumof(2,8));
	printf("sumof(8,2): %d\n", sumof(8,2));
	puts("");
	printf("sumof(3,5): %d\n", sumof(3,5));
	printf("sumof(6,4): %d\n", sumof(6,4));
}
