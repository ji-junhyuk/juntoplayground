//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d factorial: %d\n", x, factorial(x));

    return 0;
}