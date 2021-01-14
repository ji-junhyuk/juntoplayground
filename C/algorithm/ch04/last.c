//
// Created by junto on 21. 1. 5..
//

#include <stdio.h>

#define N 10

int main()
{
    int i;
    int a[N];
    int cnt = 0;
    int retry;

    puts("Enter the number");
    do {
        printf("%d number: ", cnt + 1);
        scanf("%d", &a[cnt++ % N]);
        printf("retry? 1. Yes 0. No");
        scanf("%d", &retry);
    } while (retry == 1);
    i = cnt - N;
    if (i < 0) i = 0;
    for (; i < cnt; i++)
        printf("%2d Number = %d\n", i + 1, a[i % N]);

    return 0;
}