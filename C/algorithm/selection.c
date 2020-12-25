//
// Created by junto on 12/24/20.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min])
                min = j;
            swap(int, a[i], a[min]);
    }
}

int main(void)
{
    int nx;
    int *x;

    puts("bubble sort:");
    printf("number of element: ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    puts("Ascending order.");

    for (int i = 0; i < nx; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}