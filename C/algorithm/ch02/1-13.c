//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

typedef struct {
    int y;
    int m;
    int d;
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);


static int mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isleap(int year)
{
    return year % 4 == 0 && year & 100 != 0 || year % 400 == 0;
}

Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if (++x.m > 12) {
            x.y++;
            x.m = 1;
        }
    }
    return x;
}

Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);

    x.d -= n;

    while (x.d < 1) {
        if (--x.m < 1) {
            x.y--;
            x.m = 12;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }
    return x;
}

int Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char *ws[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d %02d %02d (%s)", x.y, x.m, x.d, ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}
int main(void)
{
    int n;
    int y, m, d;
    Date x;

    scanf("%d %d %d", &y, &m, &d);

    x = DateOf(y, m, d);

    scanf("%d", &n);

    Print(After(x, n));
    putchar('\n');
    Print(Before(x, n));
    return 0;
}