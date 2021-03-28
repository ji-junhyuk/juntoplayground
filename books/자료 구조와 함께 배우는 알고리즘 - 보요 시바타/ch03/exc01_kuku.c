#include <stdio.h>

int sum(int x1, int x2)
{
	return x1 + x2;
}

int mul(int x1, int x2)
{
	return x1 * x2;
}

void kuku(int(*calc)(int, int)) //void kuku(int calc(int, int))
{
	int i, j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf("%3d", (*calc)(i,j)); //calc(int, int)
			j++;
		}
		puts("");
		i++;
	}
}

int main()
{
	kuku(sum);
	putchar('\n');
	kuku(mul);

	return 0;
}
