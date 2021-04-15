#ifndef BINTREE
#define BINTREE

#include "../ex09/Member.h"

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	Member data;
} t_btree;

t_btree *Search(t_btree *p, const Member *x);

t_btree *Add(t_btree *p, const Member *x);

int Remove(t_btree **root, const Member *x);

void PrintTree(const t_btree *p);

void FreeTree(b_tree *p);
#endif
