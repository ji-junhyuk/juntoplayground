//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    int digits = 0;
    if (x == 0)
        d[digits++] = dchar[0];
    else
        while (x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }
    return digits;
}

int main() {
    int i;
    unsigned no;
    int cd;
    int dno;
    char cno[512];
    int retry;
    do {
        scanf("%u", &no);
        do {
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        dno = card_convr(no, cd, cno);
        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
