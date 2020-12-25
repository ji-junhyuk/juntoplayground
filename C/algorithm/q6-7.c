//
// Created by junto on 12/25/20.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void selection(int a[], int n)
{
    int i, j, m;

    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min])
                min = j;
        for (int m = 0; m < n; ++m)
            printf((m == i) ? "   * " : (m == min) ? "   + " : "   ");
        putchar('\n');

        for (int m = 0; m < n; ++m)
            printf("%3d ", a[m]);
        putchar('\n');

        swap(int, a[i], a[min]);
    }
    putchar('\n');
    for (int m = 0; m < n; ++m) {
        printf("%3d ", a[m]);
    }
    putchar('\n');
}

int main(void)
{
    int i, nx;
    int *x;
    puts("straight insertion sort");

    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    puts("ascending order.");
    for (int i = 0; i < nx; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}