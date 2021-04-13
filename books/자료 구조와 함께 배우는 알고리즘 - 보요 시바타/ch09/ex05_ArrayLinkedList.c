#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ex04_ArrayLinkedList.h"

static Index GetIndex(List *list)
{
	if (list->deleted == NULL)
		return ++(list->max);
	else
	{
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;

void Initialize(List *list, int size)

Index search(List *list, const Member *x, int compare(const Member *x, const Member *y))

void InsertFront(List *list, const Member *x)

void InsertRear(List *list, const Member *x)

void RemoveFront(List *list)

void RemoveRear(List *list)

void RemoveCurrent(List *list)

void Clear(List *list)

void PrintCurrent(const List *list)

void PrintLnCurrent(const List *list)

void Print(const List *list)

void Terminate(List *list)
#endif
