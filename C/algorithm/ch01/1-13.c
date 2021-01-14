//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int i, j;

    printf("   |");
    for (i = 1; i < 10; i++)
        printf("%3d", i);

    printf("\n---+---------------------------\n");


    for (i = 1; i < 10; i++) {
        printf("%2d |", i);
        for (j = 1; j < 10; j++)
            printf("%3d", i + j);
        putchar('\n');
    }
}