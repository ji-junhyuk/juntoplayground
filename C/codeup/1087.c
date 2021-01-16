//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main(void) {
    int n;
    int sum = 0;
    int i = 0;
    scanf("%d", &n);

    while (n > sum) {
        i++;
        sum += i;
    }
    printf("%d", sum);

    return 0;
}