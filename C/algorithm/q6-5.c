//
// Created by junto on 12/25/20.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
    int i = 0, m;
    int ccnt = 0;
    int scnt = 0;
    int k = 0;

    while (k < n - 1) {
        int j;
        int last = n - 1;

        printf("pass%d: \n", ++i);
        for (int j = n - 1; j > k; --j) {
            for (int m = 0; m < n; ++m)
                printf("%3d %c", a[m], (m != j - 1) ? ' ' :
                                       (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            ccnt++;
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
                scnt++;
            }
        }
        k = last;
        for (int m = 0; m < n; ++m)
            printf("%3d  ", a[m]);
        putchar('\n');
    }
    printf("Comparison %d \n", ccnt);
    printf("Exchange %d \n", scnt);
}

int main(void)
{
    int i, nx;
    int *x;

    puts("bubble sort.");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("ascending order");
    for (int i = 0; i < nx; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}