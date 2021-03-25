#include <stdio.h>

void main()
{
	int i, n, sum;
	scanf("%d", &n);

	sum = 0;
	i = 0;
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("0~n sum: %d\n", sum);
}
