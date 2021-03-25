#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void array_reverse(int a[], int n)
{
	int i;

	i = 0;
	while (i < n/2)
	{
		swap(int, a[i], a[n-i-1]);
		i++;
	}
}

int main()
{
	int i, nx;
	int *x;
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}
	puts("");
	array_reverse(x, nx);
	
	i = 0;
	while (i < nx)
	{
		printf("x[%d]: %d\n", i, x[i]);
		i++;
	}
	
	free(x);

	return 0;
}
