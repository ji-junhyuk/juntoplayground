#include <stdio.h>

void move(int no, int x, int y)
{
    char *name[] = {"A pillar", "B pillar", "C pillar"};

    if (no > 1)
        move(no - 1, x, 6 - x - y);

    printf("[%d] %s %s\n", no, name[x - 1], name[y - 1]);

    if (no > 1)
        move(no - 1, 6 - x - y, y);
}

int main(void)
{
    int n;

    printf("number of disk: ");
    scanf("%d", &n);

    move(n, 1, 3);

    return 0;
}