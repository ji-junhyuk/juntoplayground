#include <stdio.h>

void spira(int n)
{
	int i, j;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n - i)
		{
			putchar(' ');
			j++;
		}

		j = 1; 
		while (j <= (i - 1) * 2 + 1)
		{
			putchar('*');
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
	spira(n);

	return 0;
}
