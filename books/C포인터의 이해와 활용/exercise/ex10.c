#include <stdio.h>

void main()
{
	int num = 5;
	const int limit = 500;
	int *pi;
	const int *pci;

	pi = &num;
	pci = &limit;
	
	printf("num %p %d\n", &num, num);
	printf("limit %p %d\n", &limit, limit);
	printf("pi %p %d\n", &pi, *pi);
	printf("pci %p %d\n", &pci, *pci);
}
