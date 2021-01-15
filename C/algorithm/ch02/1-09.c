//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void ary_rcopy(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = b[i];

    for (i = 0; i < n / 2; i++)
        swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
    int i;
    int *x, *y;
    int n;

    scanf("%d", &n);
    x = calloc(n, sizeof(int));
    y = calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);

    ary_rcopy(y, x, n);

    for (i = 0; i < n; i++)
        printf("y[%d] = %d\n", i, y[i]);

    free(x);
    free(y);

    return 0;
}