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
	PDATA p = head, n = nodeAlloc(data);

	if (head == NULL)
		return n;
	while (p->link)
		p = p->link;
	p->link = n;

	return head;
}

PDATA deleteNode(PDATA head, int data)
{
	PDATA p = head, pp;
	while (p && p->data != data)
	{
		pp = p;
		p = p->link;
	}
	if (p == NULL)
		puts("자료가 없습니다.");
	else if (p == head)
	{
		head = p->link;
		free(p);
	}
	else 
	{
		pp->link = p->link;
		free(p);
	}
	return head;
}

void printNode(PDATA p)
{
	for (; p; p= p->link)
		printf("%d\n", p->data);
}

void main()
{
	PDATA head = NULL, p = NULL;

	head = insertNode(head, 10);
	head = insertNode(head, 20);
	head = insertNode(head, 30);
	head = insertNode(head, 40);
	head = insertNode(head, 50);

	printNode(head);
	head = deleteNode(head, 30);
	head = deleteNode(head, 10);

	puts("");
	printNode(head);
}
