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
	Node *p = AllocNode(10);

	printf("%d\n", p->data);

	free(p);
}
