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
	Node *p = NULL;

	p = AllocNode(10);
	head = p;

	p = AllocNode(20);
	head->next = p;
	p->prev = head;

	p = AllocNode(30);
	head->next->next = p;
	p->prev = head->next;

	printf("%d\n", head->data);
	printf("%d\n", head->next->data);
	printf("%d\n", head->next->next->data);

	free(head->next->next);
	free(head->next);
	free(head);
}
