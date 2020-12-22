//
// Created by junto on 12/22/20.
//

#include <stdio.h>

void recur(int n)
{
    if (n > 0) {
        recur(n - 2);
        printf("%d\n", n);
        recur(n - 1);
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