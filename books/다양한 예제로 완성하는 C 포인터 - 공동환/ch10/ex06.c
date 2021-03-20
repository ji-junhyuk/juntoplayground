#include <stdio.h>
#include <stdlib.h>
void main()
{
	int (*arr)[3];

	arr = (int (*)[3])malloc(sizeof(int)*3*3);

	arr[0][0] = 10; arr[0][1] = 20; arr[0][2] = 30;
	
	printf("%d %d %d\n", arr[0][0], arr[0][1], arr[0][2]);
	free(arr);
}
