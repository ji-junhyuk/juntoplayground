//
// Created by junto on 21. 1. 21..
//

#include <stdio.h>

int str_len (const char *s)
{
    int len = 0;
    while (*s++)
        len++;

    return len;
}

int main (void)
{
    char str[256];
    scanf("%s", str);
    printf("%d\n", str_len(str));

    return 0;
}