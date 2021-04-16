b_tree *GetMinNode(const b_tree *p)
{
	if (p == NULL)
		return NULL;
	else
	{
		while (p->left != NULL)
			p = p->left;
		return p;
	}
}

b_tree *GetMaxNode(const b_tree *p)
{
	if (p == NULL)
		return NULL;
	else
	{
		while (p->right != NULL)
			p = p->right;
		return p;
	}
}
