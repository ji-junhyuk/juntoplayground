#include <stdio.h>
#include <stdarg.h>
void print(int n, ...)
{
	int i;
	va_list np;
	va_start(np, n);

	for (i = 0; i < n; i++)
		printf("%d ", va_arg(np, int));
	printf("\n");
	va_end(np);
}

void main()
{
	int n1 = 10, n2 = 20, n3 = 30;

	print(1, n1);
	print(2, n1, n2);
	print(2, n2, n3);
	print(3, n1, n2, n3);
	print(3, n3, n2, n1);
}
