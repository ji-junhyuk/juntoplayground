//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int score;

    scanf("%d", &score);

    if (score >89)
        printf("%s", "A");
    else if (score > 69)
        printf("%s", "B");
    else if (score > 39)
        printf("%s", "C");
    else
        printf("%s", "D");
}