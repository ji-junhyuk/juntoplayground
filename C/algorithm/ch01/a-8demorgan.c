//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>

int main()
{
    int no;

    do {
        scanf("%d", &no);
    } while (no < 10 || no > 99);
    printf("no == %d", no);
    // Two digits numbers == !(no >= 10 & no <= 99)

    return 0;
}
