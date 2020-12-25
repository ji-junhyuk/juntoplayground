//
// Created by junto on 12/25/20.
//

#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
    int i, j;

    for (int i = 0; i < n; ++i) {
        int tmp = a[0] = a[i];
        for (j = i; a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        if (j) a[j] = tmp;
    }
}

int main(void)
{
    int i, nx;
    int *x;
    puts("straight insertion sort");

    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx + 1, sizeof(int));

    for (int i = 1; i < nx + 1; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx + 1);

    puts("ascending order.");
    for (int i = 1; i < nx + 1; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}