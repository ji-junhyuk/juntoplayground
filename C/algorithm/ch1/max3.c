//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int a, b, c;
    int max;

    printf("Find max.\n");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    max = a;
    if (b > max) max = b;
    if (c > max) max = a;

    printf("Max: %d\n", max);

    return 0;
}
