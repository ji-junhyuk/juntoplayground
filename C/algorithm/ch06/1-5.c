//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
    int i = 0;
    int m;
    int comparisonNumber = 0;
    int exchangeNumber = 0;
    int k = 0;

    while (k < n - 1) {
        int j;
        int last = n - 1;

        printf("pass%d: \n", ++i);
        for (j = n - 1; j > k; j--) {
            for (m = 0; m < n - 1; m++)
                printf("%3d %c", a[m], (m != j - 1) ? ' ' :
                                       (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            comparisonNumber++;
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
                exchangeNumber++;
            }
        }
        k = last;
        for (m = 0; m < n; m++)
            printf("%3d  ", a[m]);
        putchar('\n');
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