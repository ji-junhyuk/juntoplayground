//
// Created by junto on 21. 1. 21..
//

#include <stdio.h>
#include <limits.h>

void str_dump (const char *s)
{
    do {
        int i;
        printf("%c %0*X ", *s, (CHAR_BIT + 3) / 4, *s);
        for (i = CHAR_BIT - 1; i >= 0; i--)
            putchar(((*s >> i) & 1U) ? '1' : '0');
        putchar('\n');
    } while (*s++ != '\0');
}

int main()
{
    str_dump("STRING");
    return 0;
}