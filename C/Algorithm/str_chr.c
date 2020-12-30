//
// Created by junto on 20. 12. 30..
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

    printf("String:");
    scanf("%s", str);

    printf("Search: ");
    scanf("%s", tmp);
    ch = tmp[0];

    if ((idx = str_chr(str, ch)) == -1)
        printf(" '%c' is not in there.\n", ch);
    else
        printf(" '%c' is here %d.\n", ch, idx);
}