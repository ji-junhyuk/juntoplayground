#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *ip;

	ip = (int *)malloc(4);
	*ip = 500;

	printf("%d\n", *ip);
	free(ip);
}
