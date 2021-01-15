//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int *a;
    int na;
    scanf("%d", &na);
    a = calloc(na, sizeof(int));

    if (a == NULL)
        puts("Failed to allocate memory.");
    else {
        for (i = 0; i < na; i++)
            scanf("%d", &a[i]);
    }

    for (i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}