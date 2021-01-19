//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void insertion(int a[], int n)
{
    int i, j, m;

    for (i = 1; i < n; i++) {
        int temp = a[i];

        for (m = 0; m < n; m++)
            printf("%3d ", a[m]);
        putchar('\n');

        for (j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;

        printf("%*s%s", 4 * j, "", (i != j) ? "^-" : " ");
        for (m = 0; m < 4 * (i - j); m++)
            putchar('-');
        printf("+\n\n");
    }
    for (m = 0; m < n; m++)
        printf("%3d ", a[m]);
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

    insertion(x, nx);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}