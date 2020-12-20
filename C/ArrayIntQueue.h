//
// Created by junto on 12/20/20.
//

#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

typedef struct {
    int max;
    int num;
    int *que;
} ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);

int Enque(ArrayIntQueue *q, int x);

int Deque(ArrayIntQueue *q, int *x);

int Peek(const ArrayIntQueue *q, int *x);

void Clear(ArrayIntQueue *q);

int Capacity(const ArrayIntQueue *q);

int Size(const ArrayIntQueue *q);

int IsEmpty(const ArrayIntQueue *q);

int IsFull(const ArrayIntQueue *q);

int Search(const ArrayIntQueue *q, int x);

void Print(const ArrayIntQueue *q);

void Terminate(ArrayIntQueue *q);

#endif