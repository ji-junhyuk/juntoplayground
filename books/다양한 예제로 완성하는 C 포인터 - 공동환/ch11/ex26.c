#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int i;
	i = 0;

	while (i < 10)
	{
		srand((unsigned) time(NULL));
		printf("%d\n", rand());
		i++;
	}
}
