//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[256], s2[256];
    char *p;
    puts("strstr F");
    printf("text: ");
    scanf("%s", s1);
    printf("pattern: ");
    scanf("%s", s2);
    p = strstr(s1, s2);

    if (p == NULL)
        printf("text no pattern");
    else {
        int ofs = p - s1;
        printf("\n%s\n", s1);
        printf("%*s|\n", ofs, "");
        printf("%*s%s\n", ofs, "", s2);
    }

    return 0;
}