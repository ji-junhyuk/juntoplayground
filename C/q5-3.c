//
// Created by junto on 12/22/20.
//

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    if (y == 0)
        return (x);
    else
        return (gcd(y, x % y));
}

int gcd_array(const int a[], int n)
{
    if (n == 1)
        return (a[0]);
    else if (n == 2)
        return (gcd(a[0], a[1]));
    else
        return (gcd(a[0], gcd_array(&a[1], n - 1)));
}

int main(void)
{
    int i, nx;
    int *x;

    printf("element: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    printf("%d \n", gcd_array(x, nx));

    free(x);

    return 0;
}