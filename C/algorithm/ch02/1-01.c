//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n)
{
    int i;
    int min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int main()
{
    int i;
    int *height;
    int number;
    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    for (i = 0; i < number; i++)
        scanf("%d", &height[i]);

    printf("min: %d", minof(height, number));

    free(height);

    return 0;
}