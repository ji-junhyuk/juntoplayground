//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("great common divisor: %d", gcd(x, y));
}