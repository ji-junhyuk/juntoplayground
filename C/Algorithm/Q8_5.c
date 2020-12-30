//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

char *str_chr(const char *s, int c)
{
    c = (char)c;
    while (*s != c) {
        if (*s == '\0')
            return NULL;
        s++;
    }
    return (char *)s;
}

int main(void)
{
    char str[64];
    char tmp[64];
    int ch;
    char *idx;

    printf("String:");
    scanf("%s", str);

    printf("Search:");
    scanf("%s", tmp);
    ch = tmp[0];

    if ((idx = str_chr(str, ch)) == -1)
        printf(" %c not there", ch);
    else
        printf(" %c %d here", ch, (idx - str) + 1);

    return 0;
}