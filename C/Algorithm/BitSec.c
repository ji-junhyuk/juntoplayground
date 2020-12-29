//
// Created by junto on 20. 12. 29..
//

#include <stdio.h>
#include "BitSet.h"

int IsMember (BitSet s, int n)
{
    return s & SetOf(n);
}

/*--- 집합 s에 n을 추가 ---*/
void Add(BitSet *s, int n)
{
    *s |= SetOf(n);
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(BitSet *s, int n)
{
    *s &= ~SetOf(n);
}

/*--- 집합 s의 원소 개수를 반환 ---*/
int Size(BitSet s)
{
    int n = 0;
    for (; s != BitSetNull; n++)
        s &= s - 1;
    return n;
}

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(BitSet s)
{
    int i;
    printf("{ ");
    for (i = 0; i < BitSetBits; i++)
        if (IsMember(s, i))
            printf("%d ", i);
    printf("}");
}

/*--- 집합 s의 모든 원소를 ​​출력(줄 바꿈 문자 포함) ---*/
void PrintLn(BitSet s)
{
    Print(s);
    putchar('\n');
}