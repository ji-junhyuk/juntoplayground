//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

void spira(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n-i ; j++)
            putchar(' ');
        for (j = 1; j <= (i - 1) * 2 + 1; j++)
            printf("%d", i % 10);
        putchar('\n');
    }
}

int main(void)
{
    int n;

    scanf("%d", &n);

    spira(n);

    return 0;
}