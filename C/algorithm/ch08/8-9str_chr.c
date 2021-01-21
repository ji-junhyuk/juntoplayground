//
// Created by junto on 21. 1. 21..
//

#include <stdio.h>

int str_chr(const char *s, int c)
{
    int i = 0;
    c = (char) c;
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

    scanf("%s", str);

    scanf("%s", tmp);
    ch = tmp[0];

    if ((idx = str_chr(str, ch)) == -1)
        printf("%c is not here\n", ch);
    else
        printf("%c is %d\n", ch, idx + 1);

    return 0;
}