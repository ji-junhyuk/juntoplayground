#include <stdio.h>

int main(void)
{
	int i, n, sum;

	scanf("%d", &n);
	sum = 0;
	for (i = 0; i <= n; i++)
		sum += i;
	printf("0~n sum: %d\n", sum);

	return 0;
}
