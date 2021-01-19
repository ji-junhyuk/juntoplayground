//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void selection(int a[], int n)
{
	int i, j, m;

	for (i = 0; i < n - 1; i++) {
        int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		for (m = 0; m < n; m++)
			printf((m == i) ? "  * " : (m == min) ? "  + " : "    ");
		putchar('\n');

		for (m = 0; m < n; m++)
			printf("%3d ", a[m]);
		putchar('\n');

		swap(int, a[i], a[min]);
	}
	putchar('\n');
	for (m = 0; m < n; m++)
		printf("%3d ", a[m]);
	putchar('\n');
}

int main(void)
{
    int i, nx;
    int *x;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}