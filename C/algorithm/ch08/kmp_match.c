//
// Created by junto on 21. 1. 10..
//
#include <stdio.h>

int kmp_match(const char txt[], const char pat[])
{
    int pt = 1;
    int pp = 0;
    int skip[1024];

    skip[pt] = 0;
    while (pat[pt] != '\0') {
        if (pat[pt] == pat[pp])
            skip[++pt] == ++pt;
        else if (pp == 0)
            skip[++pt] = pp;
        else
            pp = skip[pp];
    }

    pt = pp = 0;
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++; pp++;
        } else if (pp == 0)
            pt++;
        else
            pp = skip[pp];
    }
    if (pat[pp] == '\0')
        return pt - pp;

    return -1;
}

int main(void)
{
    int idx;
    char s1[256];
    char s2[256];
    puts("KMP");
    printf("text: ");
    scanf("%s", s1);
    printf("pattern: ");
    scanf("%s", s2);

    idx = kmp_match(s1, s2);
    if (idx == -1) {
        puts("no pattern in text");
    } else {
        printf("%d match\n", idx + 1);
    }

    return 0;
}