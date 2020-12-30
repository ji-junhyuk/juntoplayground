//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

void swap_ptr(char **x, char **y)
{
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void)
{
 char *s1 = "ABCD";
 char *s2 = "EFGH";

    printf("pointer s1 %s \n", s1);
    printf("pointer s2 %s \n", s2);

    swap_ptr(&s1, &s2);

}