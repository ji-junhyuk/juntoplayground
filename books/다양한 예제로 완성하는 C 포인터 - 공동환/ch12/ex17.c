#include <stdio.h>
void main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int *ap = arr;
	int i;

	i = 0;
	while (i < 5)
	{
		printf("%d\n", *ap);
		*ap++;
		i++;
	}
	puts("");
	printf("%p %p\n", arr, ap);
}
