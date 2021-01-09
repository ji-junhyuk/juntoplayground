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
- 선형 검색: **무작위**로 늘어놓은 데이터 모임에서 검색을 수행한다.
- 이진 검색: **일정한 규칙**으로 늘어놓은 데이터 모임에서 아주 빠른 검색을 수행한다.
- 해시법: 추가, 삭제가 자주 일어나는 데이터 모임에서 아주 빠른 검색을 수행한다.

# #4 스택
# 이론
- 스택: 스택(stack)은 데이터를 일시적으로 저장하기 위해 사용하는 자료구조로, 데이터의 입력과 출력 순서는 후입선출(LIFO, Last In First Out)이다.
  - **stk**: **스택으로 푸쉬된 데이터를 저장할 용도의 배열**을 가리키는 포인터이다. 가장 먼저 푸쉬된 데이터를 저장하는 곳은 stk[0]이다.
  - **max**: **스택의 최대 용량**을 나타나는 멤버이다. 이 값은 배열 stk의 요소 개수와 같다.
  - **ptr**: **스택에 쌓여 있는 데이터의 개수**를 나타내는 멤버이다. 이 값을 스택 포인터(stack pointer)라고 한다. 가장 먼저 푸쉬된 바닥의 데이터는 stk[0], 가장 나중에 푸쉬된 꼭대기(top) 데이터는 stk[ptr-1]이다.
- 큐: 큐(queue)는 데이터를 일시적으로 저장하기 위해 사용하는 자료구조로, 데이터의 입력과 출력의 순서는 선입선출(FIFO, First In First Out)이다.

> stack
```c
int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0;
}

int Capacity(const IntStack *s)
{
    return s->max;
}

int Size(const IntStack *s)
{
    return s->ptr;
}

int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int x)
{
    int i;
    for (i = s->ptr -1; i >= 0; i--)
        if (s->stk[i] == x)
            return i;
    return -1;
}

void Print(const IntStack *s)
{
    int i;
    for (i = 0; i < s->ptr; i++)
        printf("%d ", s->stk[i]);
    putchar('\n');
}

void Terminate(IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}
```

> queue
```c
int Initialize(IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(IntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1;
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q-> max)
            q->rear = 0;
        return 0;
    }
}

int Deque(IntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

int Peek(const IntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    *x = q->que[q->front];
    return 0;
}

void Clear(IntQueue *q)
{
    q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue *q)
{
    return q->max;
}

int Size(const IntQueue *q)
{
    return q->num;
}

int IsEmpty(const IntQueue *q)
{
    return q->num <= 0;
}

int IsFull(const IntQueue *q)
{
    return q->num >= q->max;
}

int Search(const IntQueue *q, int x)
{
    int i, idx;
    for (i = 0; i < q->num; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;
    }
    return -1;
}

void Print(const IntQueue *q)
{
    int i;
    for (i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

void Terminate(IntQueue *q)
{
    if (q->que != NULL)
        free(q->que);
    q->max = q->num = q->front = q->rear = 0;
}
```
# #5 재귀
# 이론

# #6 검색
# 이론

# #7 집합
# 이론

# #8 문자열검색
# 
