//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int max4(int a, int b, int c, int d)
{
    int max;
    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d %d %d %d = %d\n", a, b, c, d, max4(a, b, c, d));
}