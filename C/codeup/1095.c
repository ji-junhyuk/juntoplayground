//
// Created by junto on 21. 1. 17..
//

#include <stdio.h>

int main(void)
{
    int n, i;
    int a[10000] = {0};
    int min;
    scanf("%d", &n);
    scanf("%d", &min);

    for (i = 2; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = 2; i <= n; i++) {
        if (a[i] < min) min = a[i];
    }
    printf("%d ", min);


    return 0;
}