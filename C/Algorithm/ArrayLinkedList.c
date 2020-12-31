//
// Created by junto on 20. 12. 31..
//

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

static Index GetIndex(List *list)
{
    if (list->deleted == NULL)
        return ++(list->max);
    else {
        Index rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return rec;
    }
}

static void DeleteIndex(List *list, Index idx)
{
    if (list->deleted == NULL) {
        list->deleted = idx;
        list->n[idx].Dnext = NULL;
    }
    else {
        Index ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

static void SetNode(Node *n, const Member *x, Index next)
{
    n->data = *x;
    n->next = next;
}

void Initialize(List *list, int size)
{
    list->n = calloc(size, sizeof(Node));
    list->head = NULL;
    list->crnt = NULL;
    list->max = NULL;
    list->deleted = NULL;
}

Index search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
    Index ptr = list->head;
    while (ptr != NULL) {
        if (compare(&list->n[ptr].data, x) == 0) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = list->n[ptr].next;
    }

    return NULL;
}

void InsertFront(List *list, const Member *x)
{
    Index ptr = list->head;
    list->head = list->crnt = GetIndex(list);
    SetNode(&list->n[list->head], x, ptr);
}

void InsertRear(List *list, const Member *x)
{
    if (list->head == NULL)
        InsertFront(list, x);
    else {
        Index ptr = list->head;
        while (list->n[ptr].next != NULL)
            ptr = list->n[ptr].next;
        list->n[ptr].next = list->crnt = GetIndex(list);
        SetNode(&list->n[list->n[ptr].next], x, NULL);
    }
}

void RemoveFront(List *list)
{
    if (list->head != NULL) {
        Index ptr = list->n[list->head].next;
        DeleteIndex(list, list->head);
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List *list)
{
    if (list->head != NULL) {
        if (list->n[list->head].next == NULL)
            RemoveFront(list);
        else {
            Index ptr = list->head;
            Index pre;
            while (list->n[ptr].next != NULL) {
                pre = ptr;
                ptr = list->n[ptr].next;
            }
            list->n[pre].next = NULL;
            DeleteIndex(list, ptr);
            list->crnt = pre;
        }
    }
}

void RemoveCurrent(List *list)
{
    if (list->head != NULL) {
        if (list->crnt == list->head)
            RemoveFront(list);
        else {
            Index ptr = list->head;
            while (list->n[ptr].next != list->crnt)
                ptr = list->n[ptr].next;
            list->n[ptr].next = list->n[list->crnt].next;
            DeleteIndex(list, list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear(List *list)
{
    while (list->head != NULL)
        RemoveFront(list);
    list->crnt = NULL;
}

void PrintCurrent(const List *list)
{
    if (list->crnt == NULL)
        printf("There's no selected node.");
    else
        PrintMember(&list->n[list->crnt].data);
}

void PrintLnCurrent(const List *list)
{
    PrintCurrent(list);
    putchar('\n');
}

void Print(const List *list)
{
    if (list->head == NULL)
        puts("There's no node.");
    else {
        Index ptr = list->head;
        puts("See all nodes.");
        while (ptr != NULL) {
            PrintLnMember(&list->n[ptr].data);
            ptr = list->n[ptr].next;
        }
    }
}

void Terminate(List *list)
{
    Clear(list);
    free(list->n);
}