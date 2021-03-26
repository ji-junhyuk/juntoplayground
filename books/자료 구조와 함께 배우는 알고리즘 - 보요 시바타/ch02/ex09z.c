#include <stdio.h>

int main()
{
	int i, n;
	unsigned long counter = 0;
	
	n = 2;
	while (n <= 1000)
	{
		i = 2;
		while (i < n)
		{
			counter++;
			if (n % i == 0)
				break;
			i++;
		}
		if (n == i)
			printf("%d\n", n);
		n++;
	}
	printf("counter: %lu\n", counter);

	return 0;
}
