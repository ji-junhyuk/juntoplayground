#include <stdio.h>
int main()
{
	char carr[5] = {'A', 'B', 'C', 'D', 'E'};
	printf("%p %p %p %p %p\n", carr, carr+1, carr+2, carr+3, carr+4);
}
