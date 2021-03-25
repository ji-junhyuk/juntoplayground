#include <stdio.h>

int main()
{
	int i, n, sum;
	scanf("%d", &n);

	i = 0, sum = 0;
	while (i <= n)
	{
		sum += i;
		printf("%d ", i);
		i++;
	}
	puts("");
	printf("i: %d\n", i);
	printf("0~n sum: %d\n", sum);

	return 0;
}
