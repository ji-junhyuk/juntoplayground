#include <stdio.h>
int main()
{
	char carr[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
	int *ap = (int *)carr;

	printf("%p %c %p %p\n", &carr[0], carr[4], &carr[8], &carr[12]);
	printf("%p %c %p %p\n", ap, *(ap+1), ap+2, ap+3);
}
