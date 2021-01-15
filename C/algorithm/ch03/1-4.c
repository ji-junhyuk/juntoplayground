//
// Created by junto on 21. 1. 16..
//

#include <stdio.h>
#include <stdlib.h>

int binary_search(const int a[], int n, int key)
{
    int i;
    int pl = 0;
    int pr = n - 1;
    int pc;

    printf("   |");
    for (i = 0; i < n; i++) printf("%4d", i);
    printf("\n---+");
    for (i = 0; i < n; i++) printf("----", i);
    printf("--\n");

    do {
        pc = (pl + pr) / 2;

        printf("   |");
        for (i = 0; i < 4 * pl; i++) printf(" ");
        printf(" <-");
        for (i = 0; i < 4 * (pc - pl); i++) printf(" ");
        printf("+");
        for (i = 0; i < 4 * (pr - pc) - 2; i++) printf(" ");
        printf("->\n");

        printf("%3d|", pc);
        for (i = 0; i < n; i++)
            printf("%4d", a[i]);
        putchar('\n');
        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return -1;
}

int main()
{
    int i, nx, ky, idx;
    int *x;
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    printf("ascending order");
    for (i = 0; i < nx; i++) {
        scanf("%d", &x[i]);
    }
    printf("search:\n");
    scanf("%d", &ky);

    idx = binary_search(x, nx, ky);

    if (idx == -1)
        puts("failed to search");
    else
        printf("%d x[%d]\n", ky, idx);

    free(x);

    return 0;
}