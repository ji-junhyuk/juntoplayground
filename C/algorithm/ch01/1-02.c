//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int min3(int a, int b, int c)
{
    int min;
    min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d %d %d = %d\n", a, b, c, min3(a, b, c));
}