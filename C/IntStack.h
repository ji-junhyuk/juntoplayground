//
// Created by junto on 12/18/20.
//

/*
#ifndef ___IntStack
#define ___IntStack

typedef struct {
    int max;
    int ptr;
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek(const IntStack *s, int *x);

void Clear(IntStack *s);

int Capacity(const IntStack *s);

int Size(const IntStack *s);

int IsEmpty(const IntStack *s);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);

#endif
*/

/* int�� ���� IntStack(���) */
#ifndef ___IntStack
#define ___IntStack

/*--- ������ �����ϴ� ����ü ---*/
typedef struct {
    int max;		/* ���� �뷮 */
    int ptr;		/* ���� ������ */
    int *stk;		/* ������ ù ��ҿ� ���� ������ */
} IntStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack *s, int max);

/*--- ���ÿ� �����͸� Ǫ��---*/
int Push(IntStack *s, int x);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack *s, int *x);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack *s, int *x);

/*--- ���� ���� ---*/
void Clear(IntStack *s);

/*--- ������ �� �뷮 ---*/
int Capacity(const IntStack *s);

/*--- ������ ������ ���� ---*/
int Size(const IntStack *s);

/*--- ������ ��� ����? ---*/
int IsEmpty(const IntStack *s);

/*--- ������ ���� á����? ---*/
int IsFull(const IntStack *s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack *s, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntStack *s);

/*--- ���� ���� ---*/
void Terminate(IntStack *s);
#endif