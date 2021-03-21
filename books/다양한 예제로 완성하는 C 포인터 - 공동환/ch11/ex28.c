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
		printf("%c\n", rand() % 26 + 97);
		i++;
	}
}
