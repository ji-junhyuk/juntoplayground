//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
    int i;
    int max = a[0];
    for (i = 0; i < n; i++)
        if (a[i] > max) max = a[i];

    return max;
}

int main(void)
{
    int i;
    int *height;
    int number;
    printf("Number of people: ");
    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    printf("Enter the %d height.\n", number);
    for (i = 0; i < number; i++) {
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }
    printf("max: %d\n", maxof(height, number));
    free(height);

    return 0;
}