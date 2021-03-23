#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *prev;
	struct _node *next;
} Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *current;
} List;

Node *AllocNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->prev = n->next = NULL;

	return n;
}

void Initialize(List *lt)
{
	lt->head = AllocNode(0);
	lt->tail = AllocNode(0);
	lt->head->next = lt->tail;
	lt->tail->prev = lt->head;
}

void Uninitialize(List *lt)
{
	Node *cur = lt->head;
	while (cur != NULL)
	{
		Node *nextCur = cur->next;
		free(cur);
		cur = nextCur;
	}
}

void AddTail(List *lt, int data)
{
	Node *n = AllocNode(data);
	Node *ptail = lt->tail->prev;
	ptail->next = n;
	n->prev = ptail;
	n->next = lt->tail;
	lt->tail->prev = n;
}

void AddHead(List *lt, int data)
{
	Node *n = AllocNode(data);
	Node *nhead = lt->head->next;
	lt->head->next = n;
	n->prev = lt->head;
	n->next = nhead;
	nhead->prev = n;
}

void RemoveTail(List *lt)
{
	Node *ptail = lt->tail->prev;
	Node *pptail = ptail->prev;
	pptail->next = lt->tail;
	lt->tail->prev = pptail;

	free(ptail);
}

void RemoveHead(List *lt)
{
	Node *nhead = lt->head->next;
	Node *nnhead = nhead->next;
	lt->head->next = nnhead;
	nnhead->prev = lt->head;

	free(nhead);
}

void Remove(List *lt)
{
	Node *prevCur = lt->current->prev;
	Node *nextCur = lt->current->next;

	prevCur->next = nextCur;
	nextCur->prev = prevCur;

	free(lt->current);
}

void Insert(List *lt, int data)
{
	Node *n = AllocNode(data);
	Node *prevCur = lt->current->prev;

	prevCur->next = n;
	n->prev = prevCur;
	n->next = lt->current;
	lt->current->prev = n;
}

int GetItem(List *lt)
{
	return lt->current->data;
}

void ResetTailPos(List *lt)
{
	lt->current = lt->tail->prev;
}

void Previous(List *lt)
{
	lt->current = lt->current->prev;
}

int HasPrevious(List *lt)
{
	return lt->current != lt->head;
}

void ResetHeadPos(List *lt)
{
	lt->current = lt->head->next;
}

void Next(List *lt)
{
	lt->current = lt->current->next;
}

int HasNext(List *lt)
{
	return lt->current != lt->tail;
}

void PrintPrevious(List *lt)
{
	printf("prev: ");
	for (ResetTailPos(lt); HasPrevious(lt); Previous(lt))
		printf("%d ", GetItem(lt));
	puts("");
}

void PrintNext(List *lt)
{
	printf("next: ");
	for (ResetHeadPos(lt); HasNext(lt); Next(lt))
		printf("%d ", GetItem(lt));
	puts("");
}

void main()
{
	List lt;

	Initialize(&lt);
	AddTail(&lt, 10);
	AddTail(&lt, 20);
	AddTail(&lt, 30);

	PrintNext(&lt);
	PrintPrevious(&lt);

	AddHead(&lt, 100);
	AddHead(&lt, 200);
	AddHead(&lt, 300);

	PrintNext(&lt);
	PrintPrevious(&lt);

	Uninitialize(&lt);
}
