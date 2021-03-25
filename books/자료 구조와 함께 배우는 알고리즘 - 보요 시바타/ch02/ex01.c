#include <stdio.h>
#define N 10
int main(void)
{
	int i;
	int array[N];
	
	i = 0;
	while (i < N)
	{
		printf("array[%d]: ", i);
		scanf("%d", &array[i]);
		i++;
	}
	puts("");

	i = 0;
	while (i < N)
	{
		printf("array[%d]: %d\n", i, array[i]);
		i++;
	}

	return 0;
}
