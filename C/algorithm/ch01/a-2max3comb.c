//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int max3(int a, int b, int c)
{
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    return max;
}

int main(void)
{
    printf("%d %d %d = %d\n", 3, 2, 1, max3(3, 2, 1));
    printf("%d %d %d = %d\n", 3, 2, 2, max3(3, 2, 2));
    printf("%d %d %d = %d\n", 3, 1, 2, max3(3, 1, 2));

    return 0;
}