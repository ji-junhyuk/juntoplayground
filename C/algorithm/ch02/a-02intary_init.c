//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

int main()
{
    int i;
    int a[5] = {1, 2, 3, 4, 5,};
    int na = sizeof(a) / sizeof(a[0]);
    printf("%d", na);

    putchar('\n');
    for (i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);
}