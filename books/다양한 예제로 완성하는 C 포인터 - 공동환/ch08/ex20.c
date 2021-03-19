#include <stdio.h>
void func(double *dp)
{
	printf("%p %g\n", dp, *dp);
}

void main()
{
	double d = 3.141592;
	func(&d);
}
