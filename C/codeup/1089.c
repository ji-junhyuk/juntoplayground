//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>

int main(void) {
    int i, j, a, b ,c;
    scanf("%d %d %d", &a, &b, &c);
    for (i = a, j = 1; ;j++, i+=b)
        if(j==c) break;
    printf("%d", i);
    return 0;
}
