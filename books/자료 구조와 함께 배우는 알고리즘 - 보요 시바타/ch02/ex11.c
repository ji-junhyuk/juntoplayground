#include <stdio.h>

int main()
{
	int i, n;
	int prime[500];

	int ptr = 0;
	unsigned long counter = 0;

	prime[ptr++] = 2;
	prime[ptr++] = 3;

	n = 5;
	while (n <= 1000)
	{
		int flag = 0;
		i = 1;
		while (prime[i] * prime[i] <= n)
		{
			counter++;
			if (n % prime[i] == 0)
			{
				counter++;
				flag = 1;
				break;
			}
			i++;
		}
		if (!flag)
			prime[ptr++] = n;
		n+=2;
	}

	puts("");
	i = 0;
	while (i < ptr)
	{
		printf("%d\n", prime[i]);
		i++;
	}
	printf("counter: %lu\n", counter);

	return 0;
}
