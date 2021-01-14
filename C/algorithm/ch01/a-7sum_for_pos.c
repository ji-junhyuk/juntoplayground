//
// Created by junto on 21. 1. 14..
//
#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    int sum = 0;
    do {
        scanf("%d", &n);
    } while (n <= 0);

    while (i <= n) {
        sum += i;
        i++;
    }
    printf("1 to %d sum: %d", n, sum);

    return 0;
}