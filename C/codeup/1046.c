//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>

int main()
{
    int a, b, c, sum;
    float avg;
    scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;
    avg = (float)sum / 3;
    printf("%d\n%.1f\n", sum, avg);
}