//
// Created by junto on 12/25/20.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void shaker(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int last = right;

    while (left < right) {
        for (int j = right; j < left; --j) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j-1],a[j]);
                last = j;
            }
        }
        left = last;

        for (int j = left; j < right; ++j) {
            if (a[j] > a[j + 1]) {
                swap(int, a[j], a[j+1]);
                last = j;
            }
        }
        right = last;
    }
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

    shaker(x, nx);

    puts("ascending order");
    for (int i = 0; i < nx; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}