//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void selection(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
            swap(int, a[i], a[min]);
    }
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