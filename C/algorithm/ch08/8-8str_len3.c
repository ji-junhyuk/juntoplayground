//
// Created by junto on 21. 1. 21..
//

#include <stdio.h>

int str_len (const char *s)
{
    const char *p = s;
    while (*s)
        s++;
    return s-p;
}

int main (void)
{
    char str[256];
    scanf("%s", str);
    printf("%d\n", str_len(str));

    return 0;
}