//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main()
{
    int day, a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    day = 1;
    while (day%a != 0 || day%b != 0 || day%c != 0) day++;
    printf("%d", day);
}
