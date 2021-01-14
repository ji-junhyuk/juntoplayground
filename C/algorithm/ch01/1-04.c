//
// Created by junto on 21. 1. 14..
//
#include <stdio.h>

int med3(int a, int b, int c)
{
    if (a >= b)
        if (b >= c)
            return b;
        else if (a <= c)
            return a;
        else
            return c;
    else if (a > c)
        return a;
    else if (b > c)
        return c;
    else
        return b;
}

int main()
{
    printf("%d %d %d = %d\n", 3, 2, 1, med3(3, 2, 1));
    printf("%d %d %d = %d\n", 3, 2, 2, med3(3, 2, 2));
    printf("%d %d %d = %d\n", 3, 1, 2, med3(3, 1, 2));

    return 0;
}
