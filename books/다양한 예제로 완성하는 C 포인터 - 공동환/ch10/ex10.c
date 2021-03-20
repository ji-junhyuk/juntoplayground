#include <stdio.h>
void print(...)
{
}

void main()
{
	int a = 10, b = 20, c = 30;

	print(a);
	print(a, b);
	print(a, b, c);
}
