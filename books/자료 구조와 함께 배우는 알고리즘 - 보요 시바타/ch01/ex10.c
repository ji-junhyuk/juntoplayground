#include <stdio.h>

int main(void)
{
	int i, j, n;

	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j <= i)
		{
			putchar('*');
			j++;
		}
		puts("");
		i++;
	}

	return 0;
}
