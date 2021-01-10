//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int n;
    reload:
    scanf("%d", &n);
    if (n==0) goto end;
    printf("%d\n", n);
    if (n!=0) goto reload;
    end:

    return 0;
}