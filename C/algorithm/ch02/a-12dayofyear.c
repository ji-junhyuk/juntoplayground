//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isleap(int year)
{
    return year % 4 == 0 && year & 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d)
{
    int i;
    int days = d;
    for (i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days;
}

int main(void)
{
    int year, month, day;
    int retry;
    do {
        scanf("%d %d %d", &year, &month, &day);
        printf("%d %d\n", year, dayofyear(year, month, day));
        printf("retry? 1");
    } while (retry == 1);

    return 0;
}