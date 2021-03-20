#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *ip;

	ip = (int *)malloc(sizeof(int) * 5);

	ip[0] = 1; ip[1] = 2;

	printf("%d %d\n", ip[0], ip[1]);
	free(ip);
}
