//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int i, a;
    int sum = 0;
    scanf("%d", &a);
    for (i = 1; ; i++)
    {
        sum += i;
        if (sum >= a) break;
    }
    printf("%d\n", i);

    return 0;
}