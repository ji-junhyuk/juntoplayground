# #1 기본 알고리즘
# 이론
- **알고리즘**이란 문제를 해결하기 위한 것으로, **명확**하게 정의되고 **순서**가 있는 유한 개의 규칙으로 이루어진 집합

> #1 세 정수 값을 입력하고 최대값을 구합니다.
```c
int main(void)
{
    int a, b, c;
    int max;

    printf("Find max.\n");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    max = a;
    if (b > max) max = b;
    if (c > max) max = a;

    printf("Max: %d\n", max);
    
    return 0;
}
```

<br>
</br>

> #2 세 정수의 값을 입력하고 중앙값을 구합니다.
```c
//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int med3(int a, int b, int c)
{
    if (a >= b)
        if (b >= c)
            return b;
        else if (a <= c)
            return a;
        else
            return c;
    else if (a > c)
        return a;
    else if (b > c)
        return c;
    else
        return b;
}

int main(void)
{
    int a, b, c;

    printf("Find med.\n");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    printf("med: %d", med3(a, b, c));

    return 0;
}
```

