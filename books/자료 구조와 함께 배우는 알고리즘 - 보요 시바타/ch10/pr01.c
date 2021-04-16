void PrintTreeReverse(const b_tree *p)
{
	if (p != NULL)
	{
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}
