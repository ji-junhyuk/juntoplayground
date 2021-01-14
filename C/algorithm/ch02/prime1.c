//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>

int main(void)
{
    int i, n;
    unsigned long counter = 0;
    for (n = 2; n <= 1000; n++) {
        for (i = 2; i < n; i++) {
            counter++;
            if (n % i == 0)
            break;
        }
        if (n == i)
            printf("%d\n", n);
    }
    printf("Number of divisions: %lu", counter);
}
