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

void Add(List *lt, int data)
{
	Node *n = AllocNode(data);
	Node *ptail = lt->tail->prev;
	ptail->next = n;
	n->prev = ptail;
	n->next = lt->tail;
	lt->tail->prev = n;
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

void Reset(List *lt)
{
	lt->current = lt->head->next;
}

int GetItem(List *lt)
{
	return lt->current->data;
}

void Next(List *lt)
{
	lt->current = lt->current->next;
}

int HasNext(List *lt)
{
	return lt->current != lt->tail;
}

void Print(List *lt)
{
	for (Reset(lt); HasNext(lt); Next(lt))
		printf("%d ", GetItem(lt));
	puts("");
}

void main()
{
	List lt;

	Initialize(&lt);

	Add(&lt, 10);
	Add(&lt, 20);
	Add(&lt, 30);

	for (Reset(&lt); HasNext(&lt); Next(&lt))
		if (GetItem(&lt) == 20)
			break;
	Insert(&lt, 90);
	Print(&lt);
	for (Reset(&lt); HasNext(&lt); Next(&lt))
		if (GetItem(&lt) == 90)
			break;
	Remove(&lt);
	Print(&lt);

	Uninitialize(&lt);
}
