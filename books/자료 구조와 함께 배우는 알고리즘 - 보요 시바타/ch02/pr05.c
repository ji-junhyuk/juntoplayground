#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
void array_reverse(int a[], int n)
{
	int i;
	
	i = 0;
	while (i < n/2)
	{
		printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
		swap(int, a[i], a[n-i-1]);
		printf("a[%d]과 a[%d]를 교환합니다.\n", i, n-i-1);
		i++;
	}
}

int main()
{
	int i, nx;
	int *x;
	srand(time(NULL));

	nx = 6;
	x = calloc(nx, sizeof(int));
	i = 0;
	while (i < nx)
	{
		x[i] = 120 + rand() % 91;
		printf("x[%d]: %d\n", i, x[i]);
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
