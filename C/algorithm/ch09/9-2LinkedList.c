//
// Created by junto on 21. 1. 22..
//

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;
    n->next = next;
}

void Initialize(List *list)
{
    list->head = NULL;
    list->crnt = NULL;
}

Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
    Node *ptr = list->head;
    while (ptr != NULL) {
        if (compare(&ptr -> data, x) == 0) {
            list -> crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void InsertFront(List *list, const Member *x)
{
    Node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

void InsertRear(List *list, const Member *x)
{
    if (list->head == NULL)
        InsertFront(list, x);
    else {
        Node *ptr = list->head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

void RemoveFront(List *list)
{
    if (list->head != NULL) {
        Node *ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List *list)
{
    if (list->head != NULL) {
        if ((list->head)->next == NULL)
            RemoveFront(list);
        else {
            Node *ptr = list->head;
            Node *pre;
            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;
            free(ptr);
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
            Node *ptr = list->head;
            while (ptr->next != list->crnt)
                ptr = ptr->next;
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear (List *list)
{
    while(list->head != NULL)
        RemoveFront(list);
    list->crnt = NULL;
}

void PrintCurrent(const List *list)
{
    if (list->crnt == NULL)
        printf("There is no selected node.");
    else
        PrintMember(&list->crnt->data);
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
        Node *ptr = list->head;
        puts("ALL SEE");
        while (ptr != NULL) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List *list)
{
    Clear(list);
}