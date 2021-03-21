#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int i;

	srand((unsigned) time(NULL));
	
	i = 0;
	while (i < 10)
	{
		printf("%d\n", rand() % 10);
		i++;
	}
}
