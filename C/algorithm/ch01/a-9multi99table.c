//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int i, j;
    printf("Multiplication Table\n");
    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++)
            printf("%3d", i * j);
        putchar('\n');
    }
}