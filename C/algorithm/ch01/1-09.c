//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int sumof(int a, int b)
{
    int i, min, max;
    int sum = 0;

    if (a > b) {
        min = b;
        max = a;
    }
    else {
        min = a;
        max = b;
    }

    for (i = min; i <= max; ++i)
        sum += i;

    return sum;
}

int main()

{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d + %d = %d", a, b, sumof(a, b));

    return 0;
}