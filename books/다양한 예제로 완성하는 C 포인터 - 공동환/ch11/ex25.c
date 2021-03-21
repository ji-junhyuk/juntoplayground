#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int i;
	i = 0;
	srand((unsigned) time(NULL));

	while (i < 10)
	{
		printf("%d\n", rand());
		i++;
	}
}
