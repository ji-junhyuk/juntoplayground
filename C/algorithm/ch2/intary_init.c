//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>

int main(void)
{
    int i;
    int a[5] = {1, 2, 3, 4, 5};
    int na = sizeof(a) / sizeof(a[0]);
    printf("Number of array a: %d\n", na);

    for (i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}