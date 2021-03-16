#include <stdio.h>
int main()
{
	char carr[5] = {'A', 'B', 'C', 'D', 'E'};
	printf("%c\n", *(char *)0x7ffcf13ff983);
}
