//
// Created by junto on 12/22/20.
//

#include <stdio.h>

int factorial(int n)
{
    int fact = 1;

    while (n > 1) {
        fact *= n;
        n--;
    }
    return fact;
}

int main(void)
{
    int x;

    printf("enter the number:");
    scanf("%d", &x);

    printf("%d %d\n", x, factorial(x));

    return 0;
}
