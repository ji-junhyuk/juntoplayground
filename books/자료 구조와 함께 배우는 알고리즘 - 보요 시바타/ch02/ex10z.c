#include <stdio.h>

int main()
{
	int i, n;
	int prime[500];
	
	int ptr = 0;
	unsigned long counter = 0;
	prime[ptr++] = 2;
	n = 3;
	while (n <= 1000)
	{
		i = 1;
		while (i < ptr)
		{
			counter++;
			if (n % prime[i] == 0)
				break;
			i++;
		}
		if (ptr == i)
			prime[ptr++] = n;
		n+=2;
	}

	i = 0;
	while (i < ptr)
	{
		printf("%d\n", prime[i]);
		i++;
	}
	printf("counter: %lu\n", counter);

	return 0;
}
