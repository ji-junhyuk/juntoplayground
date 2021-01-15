//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x;
    x = calloc(1, sizeof(int));
    if (x == NULL) {
        puts("failed to allocate memory.");
    } else {
        *x = 57;
        printf("*x = %d\n", *x);
        free(x);
    }

    return 0;
}