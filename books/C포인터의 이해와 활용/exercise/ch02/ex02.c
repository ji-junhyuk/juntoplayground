#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i;

	char *pc = (char *)malloc(6);
	i = 0;
	while (i < 8)
	{
		pc[i] = 0;
		i++;
	}

	i = 0;
	while (i < 8)
	{
		printf("pc[%d] = %d\n", i, pc[i]);
		i++;
	}
	return 0;
}
