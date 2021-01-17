//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main(void) {
    int r, n;
    long long int a;
    int i = 1;
    scanf("%lld %d %d", &a, &r, &n);
    while (1)
    {
        a *= r;
        i++;
        if (i == n)
            break;
    }
    printf("%lld", a);

    return 0;
}
