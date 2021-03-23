#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *link;
} DATA, *PDATA;

void main()
{
	PDATA head = NULL, p, n1, n2, n3;

	head = n1 = (PDATA)malloc(sizeof(DATA));
	n1->data = 10;
	n1->link = NULL;

	n2 = (PDATA)malloc(sizeof(DATA));
	n2->data = 20;
	n2->link = NULL;

	n3 = (PDATA)malloc(sizeof(DATA));
	n3->data = 30;
	n3->link = NULL;

	n1->link = n2;
	n2->link = n3;

	p = head;

	for (p = head; p; p = p->link)
	printf("%d\n", p->data);
}
