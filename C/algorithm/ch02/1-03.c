//
// Created by junto on 21. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>

double avgof(const a[], int n)
{
    int i;
    double sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
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

    printf("avg: %0.1f", avgof(height, number));
    free(height);

    return 0;
}