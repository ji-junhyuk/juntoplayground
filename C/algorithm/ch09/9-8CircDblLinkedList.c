//
// Created by junto on 21. 1. 22..
//

#include <stdio.h>
#include <stdlib.h>
#include "9-7CirDblLinkedList.h"

static Dnode *AllocDNode (void)
{
    return calloc(1, sizeof(Dnode));
}

static void SetDNode (Dnode *n, const Member *x, const Dnode *prev, const Dnode *next)
{
    n->data = *x;
    n->prev = prev;
    n->next = next;
}

static int IsEmpty(const Dlist *list)
{
    return list->next->next == list->head;
}

void Initialize (Dlist *list)
{
    Dnode *dummyNode = AllocDNode();
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

void PrintCurrent (const Dlist *list)
{
    if (IsEmpty(list))
        printf("There's no selected node.");
    else
        PrintMember(&list->crnt->data);
}

void PrintLnCurrent (const Dlist *list)
{
    PrintCurrent(list);
    putchar('\n');
}

Dnode *Search (Dlist *list, const Member *x,
               int compare (const Member *x, const Member *y))
{
    Dnode *ptr = list->head->next;
    while (ptr != list->head) {
        if (compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void Print (const Dlist *list)
{
    if (IsEmpty(list))
        puts("There's no node.");
    else {
        Dnode *ptr = list->head->next;
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void PrintReverse (const Dlist *list)
{
    if (IsEmpty(list))
        puts("There's no node");
    else {
        Dnode *ptr = list->head->prev;
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev;
        }
    }
}

int Next (Dlist *list)
{
    if (IsEmpty(list) || list->crnt->next == list->head)
        return 0;
    list->crnt = list->crnt->next;
    return 1;
}

int Prev (Dlist *list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;
    list->crnt = list->crnt->prev;
    return 1;
}

void InsertAfter(Dlist *list, Dnode *p, const Member *x)
{
    Dnode *ptr = AllocDNode();
    Dnode *nxt = p->next;
    p->next = p->next->prev = ptr;
    SetDNode(ptr, x, p, nxt);
    list->crnt = ptr;
}

void InsertFront(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head, x);
}

void InsertRear(Dlist *list, const Member *x)
{
    InsertAfter(list, list->head->prev, x);
}

void Remove (Dlist *list, Dnode *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev;
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

void RemoveFront (Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->next);
}

void RemoveRear (Dlist *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

void RemoveCurrent (Dlist *list)
{
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

void Clear (Dlist *list)
{
    while (!IsEmpty(list))
        RemoveFront(list);
}

void Terminate (Dlist *list)
{
    Clear(list);
    free(list->head);
}