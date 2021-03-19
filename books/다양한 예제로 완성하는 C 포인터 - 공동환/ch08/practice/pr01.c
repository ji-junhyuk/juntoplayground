#include <stdio.h>
void func(char c, int n, double d, char *str)
{
	printf("%c %d %g %s\n", c, n, d, str);
}

void main()
{
	char c = 'Z';
	int n1 = 50;
	double d = 77.777;
	char *str = "C programming";

	func(c, n1, d, str);
}
