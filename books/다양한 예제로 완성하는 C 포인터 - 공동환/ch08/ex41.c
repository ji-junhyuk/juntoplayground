#include <stdio.h>
void Print(int n)
{
	if (1 < n)
		Print(n - 1);
	printf("%d", n);
}

void main()
{
	Print(3);
}
