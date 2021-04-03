#include <stdio.h>

void main()
{
	int num = 5;
	int *pi = &num;

	*pi = 200;

	printf("%d\n", *pi);
}
