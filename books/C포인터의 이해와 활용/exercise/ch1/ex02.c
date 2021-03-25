#include <stdio.h>

void main()
{
	int num = 0;
	int *pi = &num;

	printf("%p %d\n", &num, num);
	printf("%p %p\n", &pi, pi);
}
