//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
    int i;

    printf("   |");
    for (i = 0; i < n; i++)
        printf("%3d", i);
    printf("\n---+");
    for (i = 0; i < n; i++)
        printf("---", i);
    printf("-\n");

    for (i = 0; i < n; i++) {
        int j;
        printf("   |");
        printf("%*s", 3 * (i - 1) + 5, "");
        printf("*\n");
        printf("%3d|", i);
        for (j = 0; j < n; j++)
            printf("%3d", a[j]);
        putchar('\n');

        if (a[i] == key)
            return i;

        printf("   |\n");
    }
    return -1;
}

int main()
{
    int i, nx, ky, idx;
    int *x;
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
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