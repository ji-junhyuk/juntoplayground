//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return -1;
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("Binary search");
    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("Ascending order/\n");

    printf("x[0]: ");
    scanf("%d", &x[0]);

    for (i = 1; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }

    printf("Search value:");
    scanf("%d", &ky);
    idx = bin_search(x, nx, ky);
    if (idx == -1)
        puts("Failed to search.");
    else
        printf("x[%d]: %d", idx, ky);

    free(x);

    return 0;
}