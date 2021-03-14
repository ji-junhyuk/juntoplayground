#include <stdio.h>
int main(void)
{
	int c1 = 'A';
	int c2 = 'B';

	printf("%p\n", &c1);
	printf("%p\n", &c2+1);
}
