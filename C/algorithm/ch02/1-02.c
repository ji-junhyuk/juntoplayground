//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

int sumof(const a[], int n)
{
    int i;
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];

    return sum;
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

    printf("sum: %d", sumof(height, number));
    free(height);

    return 0;
}