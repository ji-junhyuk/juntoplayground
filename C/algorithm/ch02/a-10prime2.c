//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

int main()
{
    int i, n;
    int prime[500];
    int ptr = 0;
    unsigned long counter = 0;
    prime[ptr++] = 2;
    for (n = 3; n < 1001; n += 2) {
        for (i = 1; i < ptr; i++) {
            counter++;
            if (n % prime[i] == 0)
                break;
        }
        if (ptr == i) {
            prime[ptr++] = n;
        }
    }
    for (i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("%lu", counter);
}