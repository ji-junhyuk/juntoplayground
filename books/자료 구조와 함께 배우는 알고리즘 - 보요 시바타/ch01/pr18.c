#include <stdio.h>

void nrpira(int n)
{
	int i, j;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= i - 1)
		{
			putchar(' ');
			j++;
		}

		j = 1;
		while (j <= (n - i) * 2 + 1)
		{
			printf("%d", i % 10);
			j++;
		}
		puts("");
		i++;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	nrpira(n);

	return 0;
}
