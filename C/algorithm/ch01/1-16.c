//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>
void triangleLB(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleLU(int n)
{
    int i, j;

    for (i = 1; i <=n; i++) {
        for (j = 1; j <= n - i + 1; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleRB(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i - 1; j++)
            putchar(' ');
        for (j = 1; j <= n - i + 1; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleRU(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i + 1; j++)
            putchar(' ');
        for (j = 1; j <=i; j++)
            putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    triangleLB(n);
    putchar('\n');
    triangleLU(n);
    putchar('\n');
    triangleRB(n);
    putchar('\n');
    triangleRU(n);

    return 0;
}