//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else if (x == 0)
        return y;
    else {
        int i;
        int max;
        max = x;
        if (max < y) max = y;
        for (i = max; i > 1; i--)
            if (x % i == 0 && y % i == 0)
                return i;
   }
    return 1;
}
/*
 * answer
int gcd(int x, int y)
{
    while(y != 0)
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
 */

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("great common divisor: %d", gcd(x, y));

    return 0;
}