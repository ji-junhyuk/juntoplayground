//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

int str_len (const char *s)
{
    const char *p = s;
    while (*s)
        s++;
    return s - p;
}

int main (void)
{
    char str[256];
    printf("String:");
    scanf("%s", str);
    printf("%d", str_len(str));

    return 0;
}