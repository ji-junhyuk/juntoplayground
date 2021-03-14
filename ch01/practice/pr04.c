#include <stdio.h>
int main()
{
	int n = 0x11223344;

	printf("%x\n", *(char*)&n);
	printf("%x\n", *(short*)&n);
	printf("%x\n", *(int*)&n);
}
