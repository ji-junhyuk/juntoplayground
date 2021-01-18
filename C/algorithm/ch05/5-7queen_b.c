//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int pos[8];

void print(void)
{
    int i;
    for (i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

void set(int i)
{
    int j;
    for (j = 0; j < 8; j++) {
        pos[i] = j;
        if (i == 7)
            print();
        else
            set(i + 1);
    }
}

int main(void)
{
    set(0);

    return 0;
}