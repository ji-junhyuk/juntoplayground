//
// Created by junto on 21. 1. 17..
//

#include <stdio.h>

int main()
{
    int n, i, t;
    int a[100] = {};
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        a[t] = a[t] + 1;
    }

    for (i = 1; i <= 23; i++)
        printf("%d\n", a[i]);

    return 0;
}