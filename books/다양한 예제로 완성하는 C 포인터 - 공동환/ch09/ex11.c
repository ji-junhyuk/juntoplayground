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
	int (*pFunc_cdecl)(int, int);

	pFunc_cdecl = Add_cdecl;

	printf("10 + 20 = %d", pFunc_cdecl(10, 20));
}
