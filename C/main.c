#include <stdio.h>

int main(void)
{
    int i, j, n;
    do {
        printf("What floor triangle: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
