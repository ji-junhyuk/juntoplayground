#include <stdio.h>
#include <string.h>
void main()
{
	char c = 'A';

	memset(&c, 0, sizeof(char));
	
	printf("%c %d\n", c, c);
}
