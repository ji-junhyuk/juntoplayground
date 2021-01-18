//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

void move(int no, int x, int y)
{
    char *name[] = {"A", "B", "C"};

    if (no > 1)
        move(no - 1, x, 6 - x - y);
    printf("[%d] %s %s\n", no, name[x - 1], name[y - 1]);

    if (no > 1)
        move(no - 1, 6 - x - y, y);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}