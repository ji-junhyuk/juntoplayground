#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y;

    srand(time(NULL));
    x = rand() % 6;
    y = rand() % 6;

    printf("%d, %d\n", x, y);
}