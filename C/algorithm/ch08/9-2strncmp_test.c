//
// Created by junto on 21. 1. 21..
//

#include <stdio.h>
#include <string.h>

int main ()
{
    char st[128];
    puts("STRING Compare to the first 3 characters.");

    while (1) {
        scanf("%s", st);
        if (strncmp("XXXX", st, 3) == 0)
            break;
        printf("strncmp(STRING, st, 3) = %d\n", strncmp("STRING", st, 3));
    }

    return 0;
}