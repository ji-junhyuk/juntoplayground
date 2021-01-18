//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

int flag[8];
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
        if (!flag[j]) {
            pos[i] = j;
            if (i == 7)
                print();
            else {
                flag[j] = 1;
                set(i + 1);
                flag[j] = 0;
            }
        }
    }
}

int main(void)
{
    int i;
    for (i = 0; i < 8; i++)
        flag[i] = 0;
    set(0);

    return 0;
}