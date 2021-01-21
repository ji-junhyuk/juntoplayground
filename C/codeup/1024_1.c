//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>

int main()
{
    int i;
    char data[30];
    scanf("%s", data);
    for (i = 0; data[i]!='\0'; i++)
        printf("\'%c\'\n", data[i]);
}
