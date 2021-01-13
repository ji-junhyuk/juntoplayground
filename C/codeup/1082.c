//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int i, n;

    scanf("%X", &n);

    for (i = 1; i < 16; i++) {
        printf("%X*%X=%X\n", n, i, n * i);
    }

    return 0;
}