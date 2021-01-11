//
// Created by junto on 21. 1. 11..
//

#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node {
    Member data;
    struct __node *next;
} Node;

typedef struct {
    Node *head;
    Node *crnt;
} List;

void Initialize(List *list);

Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y));

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
