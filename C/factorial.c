//
// Created by junto on 12/22/20.
//

#include <stdio.h>

int factorial(int n)
{
    if (n>0)
        return n * factorial(n - 1);
    else
        return 1;
}

int main(void )
{
    int x;
    printf("enter the number");
    scanf("%d", &x);
    printf("%d %d\n", x, factorial(x));

    return 0;
}
