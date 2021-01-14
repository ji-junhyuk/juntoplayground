//
// Created by junto on 21. 1. 9..
//

#include <stdio.h>
#include "IntSet.h"

int main(void)
{
    IntSet s1, s2, s3;
    Initialize(&s1, 24);
    Initialize(&s2, 24);
    Initialize(&s3, 24);

    Add(&s1, 10);
    Add(&s1, 15);
    Add(&s1, 20);
    Add(&s1, 25);

    Assign(&s2, &s1);
    Add(&s2, 12);
    Remove(&s2, 20);
    Assign(&s3, &s2);

    printf("s1= ");PrintLn(&s1);
    printf("s2= ");PrintLn(&s2);
    printf("s3= ");PrintLn(&s3);

    printf("s1 15 %s\n", IsMember(&s1, 15) > 0 ? "O" : "X");
    printf("s2 25 %s\n", IsMember(&s2, 25) > 0 ? "O" : "X");
    printf("s1 %s s2\n", Equal(&s1, &s2) ? "O" : "X");
    printf("s2 %s s3\n", Equal(&s2, &s3) ? "O" : "X");

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&s3);

    return 0;
}