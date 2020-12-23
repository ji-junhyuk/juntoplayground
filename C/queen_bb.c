//
// Created by junto on 12/23/20.
//

#include <stdio.h>

int flag[8];
int pos[8];

void print(void)
{
    for (int i = 0; i < 8; ++i) {
        printf("%2d", pos[i]);
    }
    putchar('\n');
}

void set(int i)
{
    for (int j = 0; j < 8; ++j) {
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
    for (int i = 0; i < 8; ++i) {
        flag[i] = 0;
    }
    set(0);

    return 0;
}