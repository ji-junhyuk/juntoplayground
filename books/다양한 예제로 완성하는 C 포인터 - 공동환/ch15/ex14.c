#include <stdio.h>
#include <stdlib.h>
typedef int STACKDATA;
#define ERROR_VALUE (STACKDATA)0xfffffff

typedef struct _node
{
	STACKDATA data;
	struct _node *link;
} DATA, *PDATA;

PDATA nodeAlloc(STACKDATA data)
{
	PDATA p = (PDATA)malloc(sizeof(DATA));
	p->data = data;
	p->link = NULL;

	return p;
}

PDATA insertNode(PDATA head, STACKDATA data)
{
	PDATA p = head, n = nodeAlloc(data);

	if (head == NULL)
		return n;
	n->link = head;

	return n;
}

PDATA deleteNode(PDATA head, STACKDATA *data)
{
	PDATA p = head;

	*data = head->data;

	p = head->link;
	free(head);

	return p;
}

void Push(PDATA *head, STACKDATA data)
{
	*head = insertNode(*head, data);
}

STACKDATA Pop(PDATA *head)
{
	int data;

	if (*head == NULL)
	{
		puts("자료가 없습니다.");
		return ERROR_VALUE;
	}
	*head = deleteNode(*head, &data);

	return data;
}

void main()
{
	PDATA StackHead = NULL;

	Push(&StackHead, 100);
	Push(&StackHead, 200);
	Push(&StackHead, 300);

	printf("%d\n", Pop(&StackHead));
	printf("%d\n", Pop(&StackHead));
	printf("%d\n", Pop(&StackHead));
}
