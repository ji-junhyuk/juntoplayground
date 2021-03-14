#include <stdio.h>
int main()
{
	char c = 'A';

	printf("%p %p %p\n", &c, (char *)&c, (int *)&c);
	printf("%p %p %p\n", &c + 2, (char *)&c + 2, (int *)&c + 2);
	printf("%p %p %p\n", &c + 3, (char *)&c + 3, (int *)&c + 3);
}
