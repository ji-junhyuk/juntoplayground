//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

int card_convr(unsigned x, int n, char d[])
{
    int i;
    char dchar[] = "0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    int digits = 0;
    if (x == 0)
        d[digits++] = dchar[0];
    else {
        while (x) {
            printf("%2d | %7d ... %c\n", n, x, dchar[x % n]);
            printf("   + ----------- \n");
            d[digits++] = dchar[x % n];
            x /= n;
        }
        printf("%12d\n", x);
    }

    for (i = 0; i < digits /2; i++)
        swap(char, d[i], d[digits -i - 1]);

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
        for (i = 0; i < dno; i++)
            printf("%c", cno[i]);
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
