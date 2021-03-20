#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *ap;
	int i;

	ap = (int *)malloc(sizeof(int) * 10);

	for (i = 0; i < 10; i++)
		ap[i] = i;

	for (i = 0; i < 10; i++)
		printf("%5d", ap[i]);
	puts("");

	free(ap);
}
