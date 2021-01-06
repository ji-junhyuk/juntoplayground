//
// Created by junto on 21. 1. 6..
//

#include <stdio.h>

void move(int no, int x, int y)
{
    if (no > 1)
        move(no - 1, x, 6 - x - y);
    printf("disk[%d] shaft[%d] shaft[%d]\n", no, x, y);

    if (no > 1)
        move(no - 1, 6 - x - y, y);
}

int main(void)
{
    int n;
    printf("hanoi\nNumber of disk: ");
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}

/*
 * move(3,1,3)
 * move(2,1,2) move(3,1,3) move(2,2,3)
 * move(1,1,3) move(1,3,2) move(3,1,3) (2,2,3)
 * move(1,1,3) move(1,3,2) move(3,1,3) (1,2,1)(1,1,3)
 */