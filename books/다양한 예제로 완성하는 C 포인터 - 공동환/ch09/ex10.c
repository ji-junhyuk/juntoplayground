#include <stdio.h>
int Add_cdecl(int n1, int n2)
{
	return n1+n2;
}

int Add_stdcall(int n1, int n2)
{
	return n1+n2;
}

void main()
{
	printf("10+20 = %d", Add_cdecl(10, 20));
	printf("10+20 = %d", Add_stdcall(10, 20));
}
