//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
    int i = 0;
    while (1) {
        if (i == n)
            return -1;
        if (a[i] == key)
            return i;
        i++;
    }
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("Linear search");

    printf("Number of element: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    printf("Search value: ");
    scanf("%d", &ky);

    idx = search(x, nx, ky);
    if (idx == -1)
        puts("Failed to search.");
    else
        printf("x[%d]: %d \n", idx, ky);

    free(x);

    return 0;
}