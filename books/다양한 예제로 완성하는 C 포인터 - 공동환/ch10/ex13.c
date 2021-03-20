#include <stdio.h>
void print(int n, ...)
{
	int *ap = &n+1;

	int i = 0;
	while (i < n)
		printf("%d", ap[i++]);
	printf("\n");

}
void main()
{
	int a = 10, b = 20, c = 30;

	print(1, a);
	print(2, a, b);
	print(3, a, b, c);
}
