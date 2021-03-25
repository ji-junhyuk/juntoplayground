#include <stdio.h>
int main()
{
	int i, j, n, m;

	scanf("%d %d", &n, &m);

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("*");
			j++;
		}
		puts("");
		i++;
	}

	return 0;
}
