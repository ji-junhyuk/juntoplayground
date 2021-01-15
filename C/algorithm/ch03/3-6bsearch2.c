//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int *a, const int *b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
    // return *a < *b ? - : *a > *b ? : -1 : 0;
}

int main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
        scanf("%d", &x[i]);

    printf("Search value: ");
    scanf("%d", &ky);

    p = bsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int (*)(const void *, const void *)) int_cmpr
    );

    if (p == NULL)
        puts("Failed to search.");
    else
        printf("%d: x[%d]", ky, (int) (p - x));

    free(x);

    return 0;
}