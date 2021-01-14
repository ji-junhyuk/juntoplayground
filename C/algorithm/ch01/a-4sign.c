//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    if (n > 0)
        printf("Positive number");
    else if (n < 0)
        printf("Negative number");
    else
        printf("0");

    return 0;
}