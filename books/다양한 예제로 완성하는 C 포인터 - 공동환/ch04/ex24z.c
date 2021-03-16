#include <stdio.h>
int main()
{
	char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
	char *carr[5] = {&a, &b, &c, &d, &e};

	printf("%p %p %p %p %p\n", &a, &b, &c, &d, &e);
	printf("%p %p %p %p %p\n", carr[0], carr[1], carr[2], carr[3], carr[4]);

	printf("%c %c %c %c %c\n", a, b, c, d, e);
	printf("%c %c %c %c %c\n", *carr[0], *carr[1], *carr[2], *carr[3], *carr[4]);
}
