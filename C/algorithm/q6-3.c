//
// Created by junto on 12/24/20.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int is_sorted(int a[], int n)
{
    for (int i = n - 1; i > 0; --i) {
        if (a[i - 1] > a[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    int i, nx, sorted;
    int *x;

    puts("bublle sort deepening");
    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    sorted = is_sorted(x, nx);

    if (sorted)
        puts("array is arranged.");
    else
        puts("array is not arranged.");

    free(x);

    return 0;
}