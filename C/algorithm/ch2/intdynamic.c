//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    x = calloc(1, sizeof(int));
    if (x == NULL) {
        puts("Failed to allocate memory.");
    } else {
        *x = 57;
        printf("*x = %d\n", *x);
        free(x);
    }

    return 0;
}