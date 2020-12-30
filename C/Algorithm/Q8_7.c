//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>
#include <string.h>

int str_ncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && *s2) {
        if (*s1 != *s2)
            return (unsigned char)*s1 - (unsigned  char)*s2;
        s1++;
        s2++;
        n--;
    }
    if (!n) return 0;
    if (*s1) return 1;
    return -1;
}

int main (void)
{
    char st[128];
    puts("STRING Compare to the first 3 characters.");
    puts("XXXX enter the exit");
    while (1) {
        printf("String st: ");
        scanf("%s", st);

        if (str_ncmp("XXXX", st, 3) == 0)
            break;
        printf("str_ncmp STRING, st, 3 = %d\n", str_ncmp("STRING", st, 3));
    }

    return 0;
}