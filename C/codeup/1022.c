//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>

int main()
{
    char data[2001];
    fgets(data, 2000, stdin);
    printf("%s", data);
}
