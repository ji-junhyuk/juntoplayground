//
// Created by junto on 21. 1. 11..
//

#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null -1

typedef int Index;

typedef struct {
    Member data;
    Index next;
    Index Dnext;
} Node;

typedef struct {
    Node *n;
    Index head;
    Index max; //using tail record
    Index deleted; //free list's head node
    Index crnt;
} List;

void Initialize(List *list, int size);

Index search(List *list, const Member *x, int compare(const Member *x, const Member *y));

void InsertFront(List *list, const Member *x);

void InsertRear(List *list, const Member *x);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintLnCurrent(const List *list);

void Print(const List *list);

void Terminate(List *list);

#endif
