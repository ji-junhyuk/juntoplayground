#include <stdio.h>
int main()
{
	char carr[5] = {1, 2, 3, 4, 5};

	printf("%p %p\n", carr, &carr[0]);
}
