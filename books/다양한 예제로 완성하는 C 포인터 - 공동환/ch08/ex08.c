#include <stdio.h>
void func(char c, int n, double d)
{
	printf("%c %d %g\n", c, n, d);
}

int main()
{
	func('A', 5, 5.23);
	func('b', 10, 3.23);
	func('-', 1230, 123.4838223);
}
