//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
    int i, j, m;
    int comparisonNumber = 0;
    int exchangeNumber = 0;

    for (i = 0; i < n - 1; i++) {
        int exchange = 0;
        printf("pass%d: \n", i + 1);

        for (j = n - 1; j > i; j--) {
            for (m = 0; m < n - 1; m++)
                printf("%3d %c", a[m], (m != j - 1) ? ' ' :
                                       (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            comparisonNumber++;
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                exchange++;
                exchangeNumber++;
            }
        }
        for (m = 0; m < n; m++)
            printf("%3d  ", a[m]);
        putchar('\n');
        if (exchange == 0) break;
    }
    printf("comparison: %d\n", comparisonNumber);
    printf("exchange: %d\n", exchangeNumber);
}

int main(void)
{
    int i, nx;
    int *x;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}