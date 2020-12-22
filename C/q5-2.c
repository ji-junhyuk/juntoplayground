//
// Created by junto on 12/22/20.
//

#include <stdio.h>

int gcd(int x, int y)
{
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main(void)
{
    int x, y;

    puts("gcd");
    printf("enter the number");
    scanf("%d", &x);
    printf("enter the number");
    scanf("%d", &y);

    printf("gcd: %d", gcd(x, y));

    return 0;
}