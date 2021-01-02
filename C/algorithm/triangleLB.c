//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int i, j, n;
    do {
        printf("What floor is the triangle?");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        putchar('\n');
    }

    return 0;
}