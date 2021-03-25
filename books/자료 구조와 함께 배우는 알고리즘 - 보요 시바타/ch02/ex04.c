#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, na;
	int *a;

	scanf("%d", &na);
	a = calloc(na, sizeof(int));

	if (a == NULL)
		puts("failed to allocate memory");
	else
	{
		i = 0;
		while (i < na)
		{
			printf("a[%d]: ", i);
			scanf("%d", &a[i]);
			i++;
		}
		puts("");

		i = 0;
		while (i < na)
		{
			printf("a[%d] = %d\n", i, a[i]);
			i++;
		}
		free(a);
	}
	return 0;
}
