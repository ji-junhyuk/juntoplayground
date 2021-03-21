#include <stdio.h>
#include <stdlib.h>
void main()
{
	char c;
	int n;
	double d;
	char *temp = "A 200 255.123";

	sscanf(temp, "%c %d %lf", &c, &n, &d);
	printf("%c %d %g\n", c, n, d);
}
