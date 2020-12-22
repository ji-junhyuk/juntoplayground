//
// Created by junto on 12/22/20.
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
    int a = 24;
    int b = a % 32;
    printf("%d", b);
    int x,y;
    puts("gcd.");
    printf("enter the number");
    scanf("%d", &x);
    printf("enter the number");
    scanf("%d", &y);
    printf("%d", gcd(x, y));

    return 0;
}