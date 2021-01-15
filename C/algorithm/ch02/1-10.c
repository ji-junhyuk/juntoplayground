//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void shuffle(int a[], int n)
{
    int i;

    srand(time(NULL));
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        if (i != j)
            swap(int, a[i], a[j]);
    }
}

int main(void)
{
    int i;
    int *x, *y;
    int nx;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
        scanf("%d", &x[i]);

    shuffle(x, nx);

    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}