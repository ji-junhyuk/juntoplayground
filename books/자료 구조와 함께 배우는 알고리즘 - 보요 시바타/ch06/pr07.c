#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void selection(int a[], int n)
{
	int i, j, m, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		for (m = 0; m < n; m++)
	    //		printf((m == i) ? "  * " : (m == min) ? " + " : "   ");
			printf("%3c", (m == i) ? '*' : (min == m) ? '+' : ' ');
		puts("");
		for (m = 0; m < n; m++)
			printf("%3d", a[m]);
		puts("");
		
		swap(int, a[i], a[min]);
	}
	for (m = 0; m < n; m++)
		printf("%3d", a[m]);
	puts("");

}



int main()
{
	int i, nx;
	int *x;

	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}

	selection(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
