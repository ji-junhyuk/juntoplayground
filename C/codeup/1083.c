//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int i = 1;
    int n;

    scanf("%d", &n);
    while (i <= n) {
        if (i % 3 == 0) {
            printf("X");
            printf(" ");
        }
        else {
            printf("%d", i);
            printf(" ");
        }
        i++;
    }
}