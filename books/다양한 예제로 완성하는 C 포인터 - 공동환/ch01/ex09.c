#include <stdio.h>
int main()
{
	char c = 'A';
	printf("%p\n", &c+1);
	printf("%p\n", &c+2);
	printf("%p\n", &c+3);
	printf("%p\n", &c+4);
}
