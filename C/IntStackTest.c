#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;

    if (Initialize(&s, 12) == -1) {
        puts("failed to create stack.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("data: A:%d B:%d / %d\n", Size((&s, StackA)))
    }
}