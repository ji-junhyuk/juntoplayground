//
// Created by junto on 21. 1. 9..
//
#include <stdio.h>

int main(void)
{
    int n;

    scanf("%s", &n);

    switch (n) {
        case 'A':
            printf("best!!!");
            break;
        case 'B':
            printf("good!!");
            break;
        case 'C':
            printf("run!");
            break;
        case 'D':
            printf("slowly~");
            break;
        default:
            printf("what?");
            break;
    }
}