//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main()
{
    int i, n;
    int sum = 0;
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        sum += i;
    printf("%d", sum);

    return 0;
}