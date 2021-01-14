//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>

int main(void)
{
    int i, n;
    int prime[500];
    int ptr = 0;
    unsigned long counter = 0;
    prime[ptr++] - 2;
    for (n = 3; n <= 1000; n += 2) {
        for (i = 1; i < ptr; i++) {
            counter++;
            if (n % prime[i] == 0)
                break;
        }
        if (ptr == i)
            prime[ptr++] = n;
    }
    for (i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("Number of divisions: %lu\n", counter);

    return 0;
}
