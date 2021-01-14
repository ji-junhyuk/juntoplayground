//
// Created by junto on 21. 1. 8..
//

#include <stdio.h>
#include <stdlib.h>

static int *buff;

static void __mergeSort(int a[], int left, int right)
{
    if (left < right) {
        int center = (left + right) / 2;
        int p = 0;
        int i;
        int j = 0;
        int k = left;
        __mergeSort(a, left, center);
        __mergeSort(a, center + 1, right);
        for (i = left; i <= center; i++)
            buff[p++] = a[i];
        while (i <= right && j < p)
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        while (j < p)
            a[k++] = buff[j++];
    }
}

int mergeSort (int a[], int n)
{
    if ((buff = calloc(n, sizeof(int))) == NULL)
        return -1;
    __mergeSort(a, 0, n - 1);
    free(buff);
    return 0;
}

int main(void)
{
    int i, nx;
    int *x;
    puts("merge sort");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    mergeSort(x, nx);
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}