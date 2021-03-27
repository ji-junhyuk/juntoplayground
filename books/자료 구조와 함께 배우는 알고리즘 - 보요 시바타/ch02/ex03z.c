#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *x;
	x = calloc(1, sizeof(int));
	if (x = NULL)
		puts("fail to allocate memory");
	else
	{
		*x = 50;
		printf("*x = %p\n", x);
		free(x);
	}

	return 0;
}
