//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter the number:");
    scanf("%d", &n);

    if (n > 0)
        printf("Positive number.\n");
    if (n < 0)
        printf("Negative number.\n");
    if (n == 0)
        printf("0");
}