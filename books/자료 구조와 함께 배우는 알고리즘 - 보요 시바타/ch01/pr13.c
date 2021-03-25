#include <stdio.h>

int main()
{
	int i, j;

	printf("   |");
	
	i = 1;
	while (i < 10)
	{
		printf("%3d", i);
		i++;
	}

	putchar('\n');
	printf("---+---------------------------\n");

	i = 1;
	while (i < 10)
	{
		printf("%3d|", i);
		j = 1;
		while (j < 10)
		{
			printf("%3d", i+j);
			j++;
		}
		puts("");
		i++;
	}

	return 0;
}
