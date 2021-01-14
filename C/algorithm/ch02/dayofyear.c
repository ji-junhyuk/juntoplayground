//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>

int mdays[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isLeap(int year)
{
    return year % 4 == 0 && year && 100 != 0 || year % 400 == 0;
}

int dayOfYear(int y, int m, int d)
{
    int i;
    int days = d;
    for (i = 1; i < m; i++)
        days += mdays[isLeap(y)][i - 1];
    return days;
}

int main(void)
{
    int year, month, day;
    int retry;

    do {
        printf("Year: "); scanf("%d", &year);
        printf("Month: "); scanf("%d", &month);
        printf("Day: "); scanf("%d", &day);
        printf("%d Since %d \n", year, dayOfYear(year, month, day));

        printf("retry? 1. yes 0. no");
        scanf("%d", &retry);
    } while (retry == 1);
}