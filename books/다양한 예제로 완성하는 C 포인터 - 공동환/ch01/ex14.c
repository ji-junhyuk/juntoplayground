#include <stdio.h>
int main()
{
	char c = 'A';

	printf("%p\n", &c);
	printf("%c %c\n", c, *&c);
}
