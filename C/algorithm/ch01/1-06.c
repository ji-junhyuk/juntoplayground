//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int i, n;
    int sum;
    scanf("%d", &n);
    sum = 0;
    i = 1;
    while (i <= n) {
        sum += i;
        i++;
        printf("%d\n", i);
    }
    printf("%d\n", sum);
}