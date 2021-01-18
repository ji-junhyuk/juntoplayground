//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int gcd_array(const int a[], int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return gcd(a[0], a[1]);
    else
        return gcd(a[0], gcd_array(&a[1], n - 1));
}

int main(void)
{
    int i, nx;
    int *x;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
        scanf("%d", &x[i]);

    printf("great common divisor: %d\n", gcd_array(x, nx));

    free(x);

    return 0;
}