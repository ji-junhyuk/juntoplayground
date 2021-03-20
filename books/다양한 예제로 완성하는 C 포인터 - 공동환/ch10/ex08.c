#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *ip;
	ip = (int *)malloc(sizeof(int)*5);
	ip[0] = 1; ip[1] = 2; ip[2] = 3; ip[3] = 4; ip[4] = 5;
	printf("%d %d %d %d %d\n", ip[0], ip[1], ip[2], ip[3], ip[4]);
	
	ip = (int *)calloc(5, sizeof(int));
	printf("%d %d %d %d %d\n", ip[0], ip[1], ip[2], ip[3], ip[4]);
	ip = (int *)realloc(ip, sizeof(int)*3);
	printf("%d %d %d %d %d\n", ip[0], ip[1], ip[2], ip[3], ip[4]);
	free(ip);
}
