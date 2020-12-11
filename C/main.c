#include <stdio.h>

int med3(int a, int b, int c)
{
    if ((b>=a && c<=a) || (b < a && c >= a))
        return a;
    else if ((a > b && c < b) || (a < b && c > b)) {
        return b;
    }
    
    return c;
}
int main()
{
    printf("%d %d %d = median: %d\n", 3, 3, 3, med3(3, 3, 3));// a=b=c
    printf("%d %d %d = median: %d\n", 3, 2, 1, med3(3, 2, 1));// b > c
    printf("%d %d %d = median: %d\n", 3, 3, 2, med3(3, 3, 2)); // (a = b)
    printf("%d %d %d = median: %d\n", 3, 1, 2, med3(3, 1, 2));// b < c
    printf("%d %d %d = median: %d\n", 3, 2, 3, med3(3, 2, 3)); // (a = c),
    printf("%d %d %d = median: %d\n", 3, 2, 2, med3(3, 2, 2));// b = c

    printf("%d %d %d = median: %d\n", 2, 3, 1, med3(2, 3, 1));// a > c
    printf("%d %d %d = median: %d\n", 2, 3, 2, med3(2, 3, 2)); // (a = c)
    printf("%d %d %d = median: %d\n", 1, 3, 2, med3(1, 3, 2));// a < c
    printf("%d %d %d = median: %d\n", 2, 3, 3, med3(2, 3, 3));// b = c

    printf("%d %d %d = median: %d\n", 2, 1, 3, med3(2, 1, 3)); // a > b
    printf("%d %d %d = median: %d\n", 1, 2, 3, med3(1, 2, 3)); // a < b
    printf("%d %d %d = median: %d\n", 2, 2, 3, med3(2, 2, 3)); // a == b

    return 0;
}

