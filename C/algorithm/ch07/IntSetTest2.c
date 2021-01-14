//
// Created by junto on 21. 1. 9..
//

#include <stdio.h>
#include "IntSet.h"

enum { ADD, RMV, SCH };

int scan_data (int sw)
{
    int data;
    switch (sw) {
        case ADD: printf("Add data: "); break;
        case RMV: printf("Remove data: "); break;
        case SCH: printf("Search data: "); break;
    }
    scanf("%d", &data);

    return data;
}

int main(void)
{
    IntSet s1, s2, temp;
    Initialize(&s1, 512);Initialize(&s2, 512); Initialize(&temp, 512);

    while (1) {
        int m, x, idx;

        printf("s1 = "); PrintLn(&s1);
        printf("s2 = "); PrintLn(&s2);
        printf("(1)Add s1 (2)Remove s1 (3)Search s1 (4)s1<-s2 (5)Various calculate\n""(6)Add s2, (7(Remove s2, (8)Search s2, (9)s2<-s1 (0)Exit\n");

        scanf("%d", &m);
        if (m == 0) break;
        switch (m) {
            case 1: x = scan_data(ADD); Add(&s1,x); break;
            case 2: x = scan_data(RMV); Remove(&s1, x); break;
            case 3: x = scan_data(SCH); idx = IsMember(&s1,x);
                printf("s1 %s\n", idx >= 0 ? "O" : "X"); break;
            case 4: Assign(&s1, &s2); break;
            case 5:
                printf("s1 == s2 = %s\n", Equal(&s1, &s2) ? "true" : "false");
                printf("s1 & s2 = "); Intersection(&temp, &s1, &s2);
                PrintLn(&temp);
                printf("s1 | s2 = "); Union(&temp, &s1, &s2);
                PrintLn(&temp);
                printf("s1 - s2 = "); Difference(&temp, &s1, &s2);
                PrintLn(&temp);
                break;
            case 6: x = scan_data(ADD); Add(&s2, x); break;
            case 7: x = scan_data(RMV); Remove(&s2, x); break;
            case 8: x = scan_data(SCH); idx = IsMember(&s2, x);
                printf("s2 %s\n", idx >= 0 ? "O" : "X"); break;
            case 9: Assign(&s2, &s1); break;
        }
    }
    Terminate(&s1); Terminate(&s2); Terminate(&temp);

    return 0;
}
