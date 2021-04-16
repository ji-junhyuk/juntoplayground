#include <stdio.h>
#include <stdlib.h>
#include "../ch09/Member.h"
#include "ex01_BinTree.h"

static t_btree *AllocNode(void)
{
	return calloc(1, sizeof(t_btree));
}

static void SetNode(t_btree *n, const Member *x, t_btree *left, t_btree *right)
{
	n->data = *x;
	n->left = left;
	n->right = right;
}

t_btree *Search(t_btree *p, const Member *x)
{
	int cond;
	if (p == NULL)
		return NULL;
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;
	else if (cond < 0)
		Search(p->left, x);
	else 
		Search(p->right, x);
}

t_btree *Add(t_btree *p, const Member *x)
{
	int cond;
	if (p == NULL)
	{
		p = AllocNode();
		SetNode(p, x, NULL, NULL);
	} else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("error: %d는 이미 등록되어 있습니다.\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

int Remove(t_btree **root, const Member *x)
{
	t_btree *next, *temp;
	t_btree **left;
	t_btree **p = root;

	while (1)
	{
		int cond;
		if (*p == NULL)
		{
			printf("error: %d는 등록되어 있지 않습니다.\n", x->no);
			return -1;
		} else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;
		else if (cond < 0)
			p = &((*p)->left);
		else
			p = &((*p)->right);
	}

	if ((*p)->left == NULL)
		next = (*p)->right;
	else 
	{
		left = &((*p)->left);
		while ((*left)->right != NULL)
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return 0;
}

void PrintTree(const t_btree *p)
{
	if (p != NULL)
	{
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
} 

void FreeTree(t_btree *p)
{
	if (p != NULL)
	{
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}
