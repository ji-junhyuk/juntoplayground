//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main(void)
{
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        if (i % 3 == 0)
            continue;
        printf("%d ", i);
    }

}