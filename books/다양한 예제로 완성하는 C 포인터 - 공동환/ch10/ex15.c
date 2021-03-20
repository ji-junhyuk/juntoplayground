#include <stdio.h>
#include <stdarg.h>
void print(int n, ...)
{
	int i;
	va_list ap;
	va_start(ap, n);

	for (i = 0; i < n; i++)
		printf("%d ", va_arg(ap,int));
	printf("\n");
	va_end(ap);
}

void main()
{
	int a = 10, b = 20, c = 30;

	print(1, a);
	print(2, a);
	print(3, a);
}
