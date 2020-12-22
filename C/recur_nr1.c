//
// Created by junto on 12/22/20.
//

#include <stdio.h>

void recur(int n)
{
    Top:
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        n = n - 2;
        goto Top;
    }
}

int main(void)
{
    int x;
    printf("enter the number");
    scanf("%d", &x);
    recur(x);

    return 0;
}

