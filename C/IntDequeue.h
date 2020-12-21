//
// Created by junto on 12/21/20.
//

#ifndef ___IntDequeue
#define ___IntDequeue

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
} IntDequeue;

int Initialize(IntDequeue *q, int max);

int EnqueFront(IntDequeue *q, int x);

int EnqueRear(IntDequeue *q, int x);

int DequeFront(IntDequeue *q, int *x);

int DequeRear(IntDequeue *q, int *x);

int PeekFront(const IntDequeue *q, int *x);

int PeekRear(const IntDequeue *q, int *x);

void Clear(IntDequeue *q);

int Capacity(const IntDequeue *q);

int Size(const IntDequeue *q);

int IsEmpty(const IntDequeue *q);

int IsFull(const IntDequeue *q);

int Search(const IntDequeue *q, int x);

int Search2(const IntDequeue *q, int x);

void Print(const IntDequeue *q);

void Terminate(IntDequeue *q);

#endif
