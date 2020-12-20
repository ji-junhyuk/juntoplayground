//
// Created by junto on 12/20/20.
//

#ifndef ___IntStack2
#define ___IntStack2

enum { StackA, StackB };

typedef struct {
	int max;
	int ptrA;
	int ptrB;
	int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int sw, int x);

int Pop(IntStack *s, int sw, int *x);

int Peek(const IntStack *s, int sw, int *x);

void Clear(IntStack *s, int sw);

int Capacity(const IntStack *s);

int Size(const IntStack *s, int sw);

int IsEmpty(const IntStack *s, int sw);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int sw, int x);

void Print(const IntStack *s, int sw);

void Terminate(IntStack *s);

#endif

//#ifndef ___IntStack2
//#define ___IntStack2
//
//enum { StackA, StackB};
//
//typedef struct {
//    int max;
//    int ptrA;
//    int ptrB;
//    int *stk;
//} IntStack;
//
//int Initialize(IntStack *s, int max);
//
//int Push(IntStack *s, int sw, int x);
//
//int Pop(IntStack *s, int sw, int *w);
//
//int Peek(const IntStack *s, int sw, int *x);
//
//void Clear(IntStack *s, int sw);
//
//int Capacity(const IntStack *s);
//
//int Size(const IntStack *s, int sw);
//
//int IsEmpty(const IntStack *s, int sw);
//
//int IsFull(const IntStack *s);
//
//int Search(const IntStack *s, int sw, int x);
//
//void Print(const IntStack *s, int sw);
//
//void Terminate(IntStack *stack);
//
//#endif