#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *link;
} DATA, *PDATA;

PDATA nodeAlloc(int data)
{
	PDATA p = (PDATA)malloc(sizeof(DATA));
	p->data = data;
	p->link = NULL;

	return p;
}

PDATA insertNode(PDATA head, int data)
{
	PDATA n = nodeAlloc(data);
	if (head == NULL)
		return n;
	n->link = head;
	return n;
}

void main()
{
	PDATA head = NULL, p = NULL;

	head = insertNode(head, 10);
	head = insertNode(head, 20);
	head = insertNode(head, 30);
	head = insertNode(head, 40);
	head = insertNode(head, 50);

	p = head;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
}
