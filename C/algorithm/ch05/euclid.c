//
// Created by junto on 21. 1. 6..
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
    int x,y;
    puts("Great common factor.");
    printf("Enter the two number\n");
    scanf("%d %d", &x, &y);
    printf("Great common factor: %d\n", gcd(x, y));
}