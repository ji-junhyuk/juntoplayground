//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main()
{
    int i, j;
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("*");
        putchar('\n');
    }

    return 0;
}