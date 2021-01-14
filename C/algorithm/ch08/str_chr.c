//
// Created by junto on 21. 1. 10..
//

#include <stdio.h>

int str_chr (const char *s, int c)
{
    int i = 0;
    c = (char)c;
    while (s[i] != c) {
        if (s[i] == '\0')
            return -1;
        i++;
    }
    return i;
}

int main(void)
{
    char str[64];
    char tmp[64];
    int ch;
    int idx;

    printf("String: ");
    scanf("%s", str);

    printf("Search String: ");
    scanf("%s", tmp);
    ch = tmp[0];

    if ((idx = str_chr(str, ch)) == -1)
        printf("%c is not there.\n", ch);
    else
        printf("%c is %d\n", ch, idx + 1);

    return 0;
}