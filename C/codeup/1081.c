//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int i, j;
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            printf("%d %d\n", i, j);

    return 0;
}