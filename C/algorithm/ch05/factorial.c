//
// Created by junto on 21. 1. 6..
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
    printf("Enter the number");
    scanf("%d", &x);
    printf("%d Sequential multiplication: %d\n", x, factorial(x));

    return 0;
}