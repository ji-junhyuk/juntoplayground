#include <stdio.h>

void main()
{
	int num;
	int *pi = &num;
	printf("%p\n", pi);

	void *pv = pi;
	pi = (int *)pv;
	printf("%p\n", pi);
}
