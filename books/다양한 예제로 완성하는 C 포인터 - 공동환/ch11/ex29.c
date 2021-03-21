#include <stdio.h>
void main()
{
	int i;

	for (i = 0; i < 100; i++)
		if (i % 10 == 0)
			printf("%d ", i);
}
