//
// Created by junto on 21. 1. 17..
//

#include <stdio.h>

int main(void)
{
    int n, i;
    int a[1001] = {};
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = n; i >= 1; i--)
        printf("%d ", a[i]);

    return 1;
}