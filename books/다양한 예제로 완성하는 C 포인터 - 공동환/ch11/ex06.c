#include <stdio.h>
void main()
{
	int c;

	c = fgetc(stdin);
	fputc(c, stdout);
}
