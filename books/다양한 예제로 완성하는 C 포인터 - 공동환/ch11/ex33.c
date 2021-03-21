#include <stdio.h>
void main()
{
	int i, n;

	i = 0;
	n = 0;
	while (i < 30)
	{
		printf("%2d", n);
		n = (n+1) % 5;
		i++;
	}
	puts("");
	
	i = 0;
	while (i < 30)
	{
		printf("%2d", n);
		n = (n+1) % 3;
		i++;
	}
	puts("");
}
