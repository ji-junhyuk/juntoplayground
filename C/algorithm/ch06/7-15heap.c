//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

static void downheap(int a[], int left, int right)
{
    int temp = a[left];
    int child;
    int parent;

    for (parent = left; parent < (right + 1) / 2; parent = child) {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;

        if (temp >= a[child])
            break;

        a[parent] = a[child];
    }

    a[parent] = temp;
}

void heapsort(int a[], int n)
{
    int i;

    for (i = (n - 1) / 2; i >= 0; i--)
        downheap(a, i, n - 1);

    for (i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
    int i, nx;
    int *x;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    heapsort(x, nx);

    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}