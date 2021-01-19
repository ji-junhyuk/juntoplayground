//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void insertion(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        int temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
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

    insertion(x, nx);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}