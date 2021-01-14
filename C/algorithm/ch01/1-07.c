//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>


int main()
{
    int i, n;
    int sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        sum += i;
        if (i == 7) {
            printf("7 = ");
        } else {
            printf("%d", i);
            printf(" + ");
        }
    }
    printf("%d", sum);

    return 0;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    int sum = 0;

    for (i = 1; i <= n; i++)
        sum += i;

    for (i = 1; i < n; i++)
        printf("%d + ", i);
    printf("%d = %d", n, sum);

    return 0;
}