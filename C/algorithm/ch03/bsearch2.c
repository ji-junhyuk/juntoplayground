//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    puts("Use bsearch function");

    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("Descending order.\n");
    printf("x[0]: ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] > x[i - 1]);
    }

    printf("Search value: ");
    scanf("%d", &ky);

    p = bsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int (*)(const void *, const void *)) int_cmp
                );

    if (p == NULL)
        puts("Failed to search.");
    else
        printf("x[%d]: %d", (int) (p - x), ky);

    free(x);

    return 0;
}