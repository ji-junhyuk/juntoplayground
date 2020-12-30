//
// Created by junto on 20. 12. 30..
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
    printf("String:");
    scanf("%s", str);
    printf("%d", str_len(str));

    return 0;
}