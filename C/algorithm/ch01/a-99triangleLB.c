//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int i, j, n;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}