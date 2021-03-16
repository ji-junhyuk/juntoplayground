#include <stdio.h>
int main()
{
	char carr[4] = {'A', 'B', 'C', 'D'};
	char (*ap)[2] = (char(*)[2])carr;

	printf("%ld %ld\n", sizeof(carr), sizeof(ap));
	printf("%p %p\n", carr, ap);
	printf("%p %p\n", ap, ap[0]);
	printf("%p %p\n", ap+1, ap[0]+1);
}
