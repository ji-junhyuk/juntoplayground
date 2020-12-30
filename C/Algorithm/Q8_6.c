//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

char *str_rchr(const char *s, int c)
{
    const char *p = NULL;

    c = (char)c;
    while (1) {
        if (*s == c)
            p = s;
        if (*s == '\0')
            break;
        s++;
    }
    return (char *)p;
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

    if ((idx = str_rchr(str, ch)) == -1)
        printf(" %c not there", ch);
    else
        printf(" %c %d here", ch, (idx - str) + 1);

    return 0;
}