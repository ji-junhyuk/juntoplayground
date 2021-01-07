//
// Created by junto on 21. 1. 7..
//

#include <stdio.h>
#include "stdlib.h"
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void bubble(int a[], int)
{
    int k = 0;
    while (k < n - 1) {
        int j;
        int last = n - 1;
        for (j = n - 1; j > k; j--)
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
    }
}

int main(void)
{
    int i, nx;
    int *x;

    puts("bubble sort");
    printf("Number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("Ascending order.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}


