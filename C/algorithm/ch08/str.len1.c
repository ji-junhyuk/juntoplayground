//
// Created by junto on 21. 1. 10..
//

#include <stdio.h>

int str_len(const char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return len;
}

int main(void)
{
    char str[256];
    printf("String: ");
    scanf("%s", str);
    printf("Length is %d\n", str_len(str));
}
