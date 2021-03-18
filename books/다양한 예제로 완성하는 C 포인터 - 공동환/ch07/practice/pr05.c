#include <stdio.h>
#include <stdlib.h>

struct _sData
{
	int *ap;
	int num;
};

int main()
{
	struct _sData data;
	data.num = 3;
	data.ap = (int *)malloc(sizeof(int)*3);

	data.ap[0] = 10; 
	data.ap[1] = 20;
	data.ap[3] = 30;
	printf("%d\n", data.num);
	printf("%d %d %d\n", data.ap[0], data.ap[1], data.ap[3]);
}
