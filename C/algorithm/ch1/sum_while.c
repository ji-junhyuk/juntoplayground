//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int i, n;
    int sum;

    puts("Sum of 1 to n.");
    printf("n: ");
    scanf("%d", &n);

    sum = 0;
    i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }

    printf("Sum of 1 to %d: %d", n, sum);
}