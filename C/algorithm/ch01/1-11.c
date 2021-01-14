//
// Created by junto on 21. 1. 14..
//
#include <stdio.h>

int main(void)
{
    int n;
    int i = 10;
    int digits = 0;

    do {
        scanf("%d", &n);
    } while (n <= 0);

    while (n > 0) {
        n /= 10;
        digits++;
    }

    printf("%d \n", digits);
    return 0;
}