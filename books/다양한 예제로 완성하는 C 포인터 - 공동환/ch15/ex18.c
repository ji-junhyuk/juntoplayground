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
	lt->head = NULL;
	lt->tail = NULL;
}

void Uninitialize(List *lt)
{
	Node *cur = lt->head;
	while (NULL != cur)
	{
		Node *nextCur = cur->next;
		free(cur);
		cur = nextCur;
	}
}

void Add(List *lt, int data)
{
	Node *n = AllocNode(data);
	if (NULL == lt->head)
	{
		lt->head = lt->tail = n;
	}
	else
	{
		lt->tail->next = n;
		n->prev = lt->tail;
		lt->tail = n;
	}
}

void Print(List *lt)
{
	Node *cur;
	for (cur = lt->head; NULL != cur; cur = cur->next)
		printf("%d ", cur->data);
	printf("\n");
}

void main()
{
	List lt;

	Initialize(&lt);

	Add(&lt, 10);
	Add(&lt, 20);
	Add(&lt, 30);

	Print(&lt);

	Uninitialize(&lt);
}
