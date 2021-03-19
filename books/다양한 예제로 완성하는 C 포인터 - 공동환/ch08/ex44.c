#include <stdio.h>
void Print(int n)
{
	printf("start : %d\n", n);
	if (1 < n)
	{
		Print(n-1);
		Print(n-2);
	}
	printf("end : %d\n", n);
}

void main()
{
	Print(3);
}
