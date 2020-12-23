//
// Created by junto on 12/23/20.
//

#include <stdio.h>

void move(int no, int x, int y)
{
    if (no > 1)
        move(no - 1, x, 6 - x - y);
    printf("%d %d %d \n", no, x, y);

    if (no > 1)
        move(no - 1, 6 - x - y, y);
}

int main(void)
{
    int n;
    printf("Hanoi, Number of disk: ");
    scanf("%d", &n);
    move(n, 1, 3);


    return 0;
}