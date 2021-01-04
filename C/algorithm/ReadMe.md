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
<br>

> #2 세 정수의 값을 입력하고 중앙값을 구합니다.
```c
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
# #2 기본 자료구조
# 이론
- **자료구조**란 데이터 단위와 데이터 자체 사이의 물리적 또는 논리적인 관계를 말한다.

> #1 배열 요소의 최대값을 구합니다(값을 난수로 생성).
```c
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
    int i;
    int max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max) max = a[i];

    return max;
}

int main(void)
{
    int i;
    int *height;
    int number;
    printf("number of people:");
    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    srand(time(NULL));
    for (i = 0; i < number; i++) {
        height[i] = 100 + rand() % 90;
        printf("height[%d] = %d\n", i, height[i]);
    }
    printf("max: %d \n", maxof(height, number));
    free(height);

    return 0;
}
```

<br>
<br>

> #2 배열 요소를 역순으로 정렬합니다.
```c
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

void ary_reverse(int a[], int n)
{
    int i;
    for (i = 0; i < n /2; i++)
        swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
    int i;
    int *x;
    int nx;

    printf("Number of element: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x, nx);
    printf("Reverse sort.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}
```

<br>
<br>

> #3 정수를 2진수 ~ 36진수로 기수 변환합니다.
```c
#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    if (x == 0)
        d[digits++] = dchar[0];
    else
        while (x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }

    return digits;
}

int main(void)
{
    int i;
    unsigned no;
    int cd;
    int dno;
    char cno[512];
    int retry;

    do {
        printf("Converted positive number: ");
        scanf("%u", &no);

        do {
            printf("What number convert? (2-36) : ");
            scanf("%d", &cd);
        } while (cd < 2 || cd> 36);

        dno = card_convr(no, cd, cno);

        printf("%d Convert\n", cd);
        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);

        printf("\nRetry? (1 Yes /0 No) : ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
```

<br>
<br> 

> #4 1000이하의 소수를 나열합니다(거듭제곱근 사용).
```c
#include <stdio.h>

int main(void)
{
    int i, n;
    int prime[500];
    int ptr = 0;
    unsigned long counter = 0;
    prime[ptr++] = 2;
    prime[ptr++] = 3;
    for (n = 5; n <= 1000; n += 2) {
        int flag = 0;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {
                flag = 1;
                break;
            }
        }
        if (! flag)
            prime[ptr++] = n;
    }
    for (i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("Number of Multiplication & division: %lu\n", counter);

    return 0;
}
```
# #3 검색
# 이론
- 



