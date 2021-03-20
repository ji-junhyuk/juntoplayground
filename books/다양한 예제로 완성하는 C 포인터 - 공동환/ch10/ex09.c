#include <stdio.h>
void main()
{
	char c = 'A';
	char *str = "ABCD";
	int n = 10;
	double d = 250.12;

	printf("%c\n", c);
	printf("%c %d\n", c, n);
	printf("%c %s %d\n", c, str, n);
	printf("%c %s %d %f\n", c, str, n, d);
}
