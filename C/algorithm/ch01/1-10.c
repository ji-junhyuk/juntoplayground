//
// Created by junto on 21. 1. 14..
//
#include <stdio.h>

int main()
{
    int a, b, minus;
    do {
        scanf("%d %d", &a, &b);
    } while (a >= b);

    minus = b - a;
    printf("%d - %d = %d\n", b, a, minus);

    return 0;
}

//int main()
//{
//    int a, b;
//
//    scanf("%d", &a);
//
//    while (1) {
//        scanf("%d", &b);
//        if (b > a) break;
//    }
//
//    printf("b - a = %d", b - a);
//
//    return 0;
//}


