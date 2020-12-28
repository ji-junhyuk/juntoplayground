//
// Created by junto on 20. 12. 28..
//

#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[], int n, int max)
{
    int i;
    int *f = calloc(max + 1, sizeof(int));
    int *b = calloc(n, sizeof(int));

    puts("before sort");
    for (i = 0; i < n; i++) printf("%3d", i);
    for (i = 0; i < n; i++) printf("---", i);
    for (i = 0; i < n; i++) printf("%3d", a[i]);

    for (i = 0; i <= max; i++) f[i] = 0;
    for (i = 0; i < n; i++) f[a[i]]++;

    puts("\nFrequency distribution");
    for (i = 0; i < max; i++) printf("%3d", i); putchar('\n');
    for (i = 0; i < max; i++) printf("---"), i; putchar('\n');
    for (i = 0; i < max; ++i) printf("%3d", f[i]); putchar('\n');

    for (i = 1; i <= max; i++) f[i] += f[i - 1];

    puts("\nCumulative frequency distribution");
    for (i = 0; i < max; i++) printf("%3d", i); putchar('\n');
    for (i = 0; i < max; i++) printf("---", i); putchar('\n');
    for (i = 0; i < max; i++) printf("%3d", f[i]); putchar('\n');

    putchar('\n');
    for (i = n - 1; i >= 0; i--) {
        b[--f[a[i]]] = a[i];
        printf("a[%2d] %2d b[%2d] \n", i, a[i], f[a[i]]);
    }

    for (i = 0; i < n; i++) a[i] = b[i];

    puts("\n after sort");
    for (i = 0; i < n; i++) printf("%3d", i); putchar('\n');
    for (i = 0; i < n; i++) printf("---", i); putchar('\n');
    for (i = 0; i < n; i++) printf("%3d", a[i]); putchar('\n');

    free(b);
    free(f);
}

int main(void)
{
    int i, nx;
    int *x;
    const int max = 100;

    puts("counting sort");
    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("0~ %d Integer\n", max);
    for (i = 0; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < 0 || x[i] > max);
    }

    countingSort(x, nx, max);

    puts("ascending order.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}