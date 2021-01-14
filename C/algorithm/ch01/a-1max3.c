//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main(void)
{
    int a, b, c;
    int max;
    scanf("%d %d %d", &a, &b, &c);
    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("max: %d", max);

    return 0;
}
