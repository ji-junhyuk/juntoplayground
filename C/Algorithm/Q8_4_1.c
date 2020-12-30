//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

size_t str_len(const char *s)
{
    size_t len = 0;

    while (s[len])
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