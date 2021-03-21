#include <stdio.h>
#include <stdlib.h>
void main()
{
	char c = 'A';
	int n = 10;

	double d = 255.123;
	char temp[20];

	sprintf(temp, "%c %d %g", c, n, d);
	puts(temp);
}
