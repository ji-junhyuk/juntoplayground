#include <stdio.h>
void Print(int n)
{
	printf("start: %d", n);
	if (1 < n)
		Print(n - 1);
	printf("end: %d", n);
}

void main()
{
	Print(3);
}
