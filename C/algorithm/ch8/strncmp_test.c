//
// Created by junto on 21. 1. 10..
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    char st[128];
    puts("STRING Compare to the first 3 Characters");
    puts("XXXX Exit");
    while (1) {
        printf("String st: ");
        scanf("%s", st);
        if (strncmp("XXXX", st, 3) == 0)
            break;
        printf("strncmp(STRing,st,3) = %d\n", strncmp("STRING", st, 3));
    }

    return 0;
}