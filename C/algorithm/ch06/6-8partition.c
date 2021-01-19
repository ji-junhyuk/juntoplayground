//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void partition(int a[], int n)
{
    int i;
    int pl = 0;
    int pr = n - 1;
    int x = a[n / 2];
    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    for (i = 0; i <= pl - 1; i++)
        printf("%d ", a[i]);
    putchar('\n');

    if (pl > pr + 1) {
        for (i = pr + 1; i <= pl - 1; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }

    for (i = pr + 1; i < n; i++)
        printf("%d ", a[i]);
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

    partition(x, nx);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}