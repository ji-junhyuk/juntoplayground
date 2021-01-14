//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int min4(int a, int b, int c, int d)
{
    int min;
    min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    return min;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d %d %d %d= %d\n", a, b, c,d, min4(a, b, c, d));
}