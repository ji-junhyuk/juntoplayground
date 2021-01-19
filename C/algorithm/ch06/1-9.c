//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void quick(int a[], int left, int right)
{
    IntStack lstack;
    IntStack rstack;

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    printf("a[%d] ~ a[%d] stack push\n", left, right);
    Push(&lstack, left);
    Push(&rstack, right);

    while (!IsEmpty(&lstack)) {
        int pl = (Pop(&lstack, &left), left);
        int pr = (Pop(&rstack, &right), right);
        int x = a[(left + right) / 2];

        printf("===============================================\n");
        printf("array range: a[%d] ~ a[%d]\n", left, right);
        printf("===============================================\n");

        do {
            while (a[pl] < x) pl++;
            while (a[pr] > x) pr--;
            if (pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while (pl <= pr);

        if (left < pr) {
            Push(&lstack, left);
            Push(&rstack, pr);

            printf("a[%d] ~ a[%d] stack push\n", left, pr);
            printf("Lstack:"); Print(&lstack);
            printf("Rstack:"); Print(&rstack);
        }
        if (pl < right) {
            Push(&lstack, pl);
            Push(&rstack, right);

            printf("a[%d] ~ a[%d]를 스택에 푸시합니다.\n", pl, right);
			printf("Lstack:");   Print(&lstack);
			printf("Rstack:");   Print(&rstack);
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);
}

int main(void)
{
    int i, nx;
    int *x;

    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);

    for (i = 0; i < nx; i++)
        printf("%d\n", x[i]);

    free(x);

    return 0;
}