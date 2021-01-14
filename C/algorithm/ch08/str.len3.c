//
// Created by junto on 21. 1. 10..
//

#include <stdio.h>

int str_len(const char *s)
{
    const char *p = s;

    while (*s)
        s++;
    return s - p;
}

int main(void)
{
    char str[256];
    printf("String: ");
    scanf("%s", str);
    printf("Length is %d\n", str_len(str));
}
