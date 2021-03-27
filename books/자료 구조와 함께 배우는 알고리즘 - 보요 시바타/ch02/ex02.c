#include <stdio.h>

int main()
{
	int i;
	int a[5] = {1,2,3,4,5};
	int na = sizeof(a) / sizeof(a[0]);
	printf("배열 a의 개수: %d\n", na);

	i = 0;
	while (i < na)
	{
		printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	
	return 0;
}
