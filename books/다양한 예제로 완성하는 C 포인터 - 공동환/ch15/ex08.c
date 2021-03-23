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

void main()
{
	PDATA head = NULL, p = NULL;

	head = p = nodeAlloc(10);

	p->link = nodeAlloc(20);

	p = p->link;
	p->link = nodeAlloc(30);

	p = head;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
}
