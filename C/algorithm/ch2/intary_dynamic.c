//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int *a;
    int na;
    printf("number of element: ");
    scanf("%d", &na);
    a = calloc(na, sizeof(int));

    if (a == NULL) {
        puts("Failed to allocate memory.");
    } else {
        printf("Enter the %d numbers.\n", na);
        for (i = 0; i < na; i++) {
            printf("a[%d]: ", i);
            scanf("%d", &a[i]);
        }
        printf("Print array all elements\n");
        for (i = 0; i < na; i++)
            printf("a[%d] = %d\n", i, a[i]);

        free(a);
    }

    return 0;
}