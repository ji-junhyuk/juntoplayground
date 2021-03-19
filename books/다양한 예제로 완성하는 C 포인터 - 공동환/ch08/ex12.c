#include <stdio.h>
double func(double d1, double d2)
{
	return d1/d2;
}

void main()
{
	double div;

	div = func(5.0, 2.0);
	printf("%g\n", div);

	div = func(50.0, 21.0);
	printf("%g\n", div);

	div = func(500.0, 211.0);
	printf("%g\n", div);
}
