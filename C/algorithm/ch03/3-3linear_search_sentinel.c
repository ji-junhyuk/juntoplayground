//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key;
    while (1) {
        if (a[i] == key)
            break;
        i++;
    }
    return i == n ? -1 : i;
}

int main()
{
    int i, nx, ky, idx;
    int *x;
    scanf("%d", &nx);

    x = calloc(nx + 1, sizeof(int));
    for (i = 0; i < nx; i++) {
        scanf("%d", &x[i]);
    }
    printf("search:\n");
    scanf("%d", &ky);

    idx = search(x, nx, ky);

    if (idx == -1)
        puts("failed to search");
    else
        printf("%d x[%d]\n", ky, idx);

    free(x);

    return 0;
}