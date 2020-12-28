//
// Created by junto on 20. 12. 28..
//

#include <stdio.h>
#include <stdlib.h>

void countingSort2(int a[], int n, int min, int max)
{
    int i;
    int *f = calloc(max - min + 2, sizeof(int));
    int *b = calloc(n, sizeof(int));

    for (i = 0; i <= max - min + 1; i++) f[i] = 0;
    for (i = 0; i < n; i++) f[a[i] - min]++;
    for (i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];
    for (i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];
    for (i = 0; i < n; i++) a[i] = b[i];

    free(b);
    free(f);
}

int main(void)
{
    int i, nx;
    int *x;
    int min, max;

    puts("counting sort");
    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("Minimum: ");
    scanf("%d", &min);

    while (1) {
        printf("Maximum: ");
        scanf("%d", &max);
        if (max > min) break;
        printf("enter the number %d UP!!", min);
    }

    printf("%d ~ %d number \n", min, max);
    for (i = 0; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < min || x[i] > max);
    }

    countingSort2(x, nx, min, max);

    puts("ascending order.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}