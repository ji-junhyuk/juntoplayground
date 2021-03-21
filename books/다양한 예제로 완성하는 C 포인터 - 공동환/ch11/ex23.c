#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i;
	
	i = 0;
	while (i < 10)
	{
		printf("%d\n", rand());
		i++;
	}
}
