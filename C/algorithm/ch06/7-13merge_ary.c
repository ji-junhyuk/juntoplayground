//
// Created by junto on 21. 1. 19..
//

#include <stdio.h>

void merge(const int a[], int na, const int b[], int nb, int c[])
{
    int pa = 0;
    int pb = 0;
    int pc = 0;

    while (pa < na && pb < nb)
        c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];

    while (pa < na)
        c[pc++] = a[pa++];

    while (pb < nb)
        c[pc++] = b[pb++];
}

int main(void)
{
    int i, na, nb;
    int *a, *b, *c;

    scanf("%d", &na);
    scanf("%d", &nb);

    a = calloc(na, sizeof(int));
    b = calloc(nb, sizeof(int));
    c = calloc(na + nb, sizeof(int));

    scanf("%d", &a[0]);
    for (i = 1; i < na; i++) {
        do {
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        } while (a[i] < a[i - 1]);
    }

    scanf("%d", &b[0]);
    for (i = 1; i < nb; i++) {
        do {
            printf("b[%d] : ", i);
            scanf("%d", &b[i]);
        } while (b[i] < b[i - 1]);
    }

    merge(a, na, b, nb, c);

    for (i = 0; i < na + nb; i++)
        printf("c[%2d] = %2d\n", i, c[i]);

    free(a);
    free(b);
    free(c);

    return 0;
}