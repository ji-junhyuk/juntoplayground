#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ch09/Member.h"
#include "ex03_ChainHash.h"

static int hash(const char *key, int size)
{
	unsigned long h = 0;

	while (*key)
		h += *(key++);

	return h % size;
}

static void SetNode(Node *n, const Member *x, Node *next)
{
	n->data = *x;
	n->next = next;
}

int Initialize(ChainHash *h, int size)
{
	int i;
	if ((h->table = calloc(size, sizeof(Node *))) == NULL)
	{
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (i = 0; i < size; i++)
		h->table[i] = NULL;
	return 1;
}

Node *Search(ChainHash *h, Member *x)
{
//	int key = hash(x->no, h->size);
	int key = hash(x->name, h->size);
	Node *p = h->table[key];

	while (p != NULL)
	{
//		if (p->data.no == x->no)
		if (!strcmp(p->data.name, x->name))
			return p;
		p = p->next;
	}
	return NULL;
}

int Add(ChainHash *h, const Member *x)
{
	// int key = hash(x->no, h->size);
	int key = hash(x->name, h->size);
	Node *p = h->table[key];

	Node *temp;
	while (p != NULL)
	{
//		if (p->data.no == x->no)
		if (!strcmp(p->data.name, x->name))
			return 1;
		p = p->next;
	}

	if ((temp = calloc(1, sizeof(Node))) == NULL)
		return 2;
	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0;
}

int Remove(ChainHash *h, const Member *x)
{
//	int key = hash(x->no, h->size);
	int key = hash(x->name, h->size);
	Node *p = h->table[key];
	Node **pp = &h->table[key];

	while (p != NULL)
	{
//		if (p->data.no == x->no)
		if (!strcmp(p->data.name, x->name))
		{
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}

void Dump(const ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++)
	{
		Node *p = h->table[i];
		printf("%02d ", i);
		while (p != NULL)
		{
			printf("-> %d : (%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

void Clear(ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++)
	{
		Node *p = h->table[i];
		while (p != NULL)
		{
			Node *next = p->next;
			free(p);
			p->next;
		}
		h->table[i] = NULL;
	}
}

void Terminate(ChainHash *h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
