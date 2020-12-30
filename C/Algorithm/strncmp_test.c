//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>
#include <string.h>

int main (void)
{
    char st[128];
    puts("STRING Compare to the first 3 characters.");
    puts("XXXX enter the exit");
    while (1) {
        printf("String st: ");
        scanf("%s", st);
        if (strncmp("XXXX", st, 3) == 0)
            break;
        printf("strncmp STRING, st, 3 = %d\n", strncmp("STRING", st, 3));
    }

    return 0;
}