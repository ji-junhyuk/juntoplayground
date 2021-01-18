//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int factorial(int n)
{
    int factorial = 1;
    while (n > 0)
        factorial *= n--;
    return factorial;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d factorial: %d\n", x, factorial(x));

    return 0;
}