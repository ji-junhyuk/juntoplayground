#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *ip;
	ip = (int *)malloc(sizeof(int) * 5);
	if (ip == NULL)
	{
		printf("메모리 할당 실패!\n");
		return ;
	}
	printf("메모리 할당 성공!");
	free(ip);
}
