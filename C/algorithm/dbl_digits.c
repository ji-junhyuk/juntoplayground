//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int no;
    printf("Enter a two-digit integer.\n");

    do {
        printf("number: ");
        scanf("%d", &no);
    } while (no < 10 || no > 99);

    printf("no: %d\n", no);

    return 0;
}