//
// Created by junto on 21. 1. 8..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void countSort(int a[], int n, int max)
{
    int i;
    int *f = calloc(max + 1, sizeof(int));
    int *b = calloc(n, sizeof(int));

    for (i = 0; i <= max; i++) f[i] = 0;
    for (i = 0; i < n; i++) f[a[i]]++;
    for (i = 1; i <= max; i++) f[i] += f[i - 1];
    for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];
    for (i = 0; i < n; i++) a[i] = b[i];
}

int main(void)
{
    int i, nx;
    int *x;
    const int max = 100;
    puts("heap sort");
    printf("number of element: ");

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("0 ~ %d, Enter the number.\n", max);

    for (i = 0; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < 0 || x[i] > max);
    }

    countSort(x, nx, max);
    puts("ascending order");

    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}