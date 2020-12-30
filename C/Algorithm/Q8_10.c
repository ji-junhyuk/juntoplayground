//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>
#include <string.h>

int bf_matchr(const char txt[], const char pat[])
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int pt = txt_len - pat_len;
    int pp;

    while (pt >= 0) {
        pp = 0;
        while (txt[pt] == pat[pp]) {
            if (pp == pat_len -1)
                return pt - pp;
            pp++;
            pt++;
        }
        pt = pt - pp - 1;
    }

    return -1;
}

int main(void)
{
    int idx;
    char s1[256];
    char s2[256];
    puts("brute force method");

    printf("text:");
    scanf("%s", s1);
    printf("pattern: ");
    scanf("%s", s2);

    idx = bf_matchr(s1, s2);

    if (idx == -1)
        puts("Text has no pattern.");
    else
        printf("%d match", idx + 1);

    return 0;
}