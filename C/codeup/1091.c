//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main()
{
    long long int a, m, d, n;
    int j;
    scanf("%lld %lld %lld %lld", &a, &m, &d, &n);

    for (j = 1; j < n; j++) {
        a *= m;
        a += d;
    }
    printf("%lld", a);

    return 0;
}
