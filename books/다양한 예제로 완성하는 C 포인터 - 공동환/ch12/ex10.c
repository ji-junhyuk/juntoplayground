#include <stdio.h>
#include <string.h>
void main()
{
	char c1 = 'A', c2 = 'A';

	if (c1 == c2)
		puts("TRUE");
	else
		puts("FALSE");

	if (memcmp(&c1, &c2, 1) == 0)
		puts("TRUE");
	else
		puts("FALSE");
}
