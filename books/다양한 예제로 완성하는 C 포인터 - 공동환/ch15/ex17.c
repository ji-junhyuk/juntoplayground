#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *prev;
	struct _node *next;
} Node;

Node *AllocNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->prev = n->next = NULL;
	return n;
}

void main()
{
	Node *head = NULL;
	Node *tail = NULL;
	Node *p = NULL;

	p = AllocNode(10);
	head = tail = p;
	
	p = AllocNode(20);
	tail->next = p;
	p->prev = tail;
	tail = p;

	p = AllocNode(30);
	tail->next = p;
	p->prev = tail;
	tail = p;

	printf("%d\n", head->data);
	printf("%d\n", head->next->data);
	printf("%d\n", head->next->next->data);

	free(head->next->next);
	free(head->next);
	free(head);
}
