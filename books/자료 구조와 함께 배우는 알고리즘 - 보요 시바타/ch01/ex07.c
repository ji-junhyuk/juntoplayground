#include <stdio.h>

int main(void)
{
	int i, n, sum;
	do {
		scanf("%d", &n);
	} while (n <= 0);

	i = 0;
	sum = 0;
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("0 to %d sum: %d\n", n, sum);

	return 0;
}
