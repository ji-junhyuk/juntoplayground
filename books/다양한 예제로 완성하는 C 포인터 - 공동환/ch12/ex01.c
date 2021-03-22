#include <stdio.h>
#include <string.h>
void main()
{
	char c1;
	char c2 = 'A';

	memcpy(&c1, &c2, sizeof(char));
	printf("%c %c\n", c1, c2);
}
