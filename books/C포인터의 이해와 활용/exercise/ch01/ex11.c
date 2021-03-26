#include <stdio.h>

int main()
{
	const int limit = 500;
	const int *const cpci = &limit;
	const int *const *pcpi = &cpci;

	printf("%d\n", *cpci);
	pcpi = &cpci;
	printf("%d\n", **pcpi);

	return 0;
}
