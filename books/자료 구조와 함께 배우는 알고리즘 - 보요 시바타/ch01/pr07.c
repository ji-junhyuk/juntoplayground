#include <stdio.h>

void main()
{
	int i, j, n, sum;

	i = 1;
	n = 7;
	sum = 0;
	while (i <= n)
	{
		printf("%d", i);
		if (i != n)
			printf(" + ");

		sum += i;
		i++;
	}
	printf(" = %d", sum);
}
