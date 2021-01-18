//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>

void recur(int n)
{
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

int main(void)
{
    int x;
    scanf("%d", &x);
    recur(x);

    return 0;
}

/***
 top-down
 bottom-up
 */


