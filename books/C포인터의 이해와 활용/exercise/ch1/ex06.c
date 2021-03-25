#include <stdio.h>

void main()
{
	int vector[] = {28,41,7};
	int *pi = vector + 2;

	printf("%d\n", *pi);
	pi -= 1;
	printf("%d\n", *pi);
	pi -= 1;
	printf("%d\n", *pi);
}
