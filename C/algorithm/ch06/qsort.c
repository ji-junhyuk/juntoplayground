//
// Created by junto on 21. 1. 8..
//

#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int i, nx;
    int *x;
    printf("qsort\n");
    printf("number of element: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    qsort(x,
          nx,
          sizeof(int),
          (int(*)(const void *, const void *))int_cmp
          );
    puts("ascending order");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}

