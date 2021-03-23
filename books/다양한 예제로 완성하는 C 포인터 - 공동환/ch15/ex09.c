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

	head = nodeAlloc(10);

	p = nodeAlloc(20);
	p->link = head;
	head = p;

	p = nodeAlloc(30);
	p->link = head;
	head = p;

	p = head;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
}
