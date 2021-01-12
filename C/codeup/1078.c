//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int j;
    int sum = 0;
    int i = 0;
    scanf("%d", &j);
    while (i <=j) {
        if (i % 2 == 0)
            sum += i;
        i++;
    }
    printf("%d", sum);
}