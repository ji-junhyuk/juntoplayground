void FreeTree(b_tree *p)
{
	if (p != NULL)
	{
		FreeTree(p->left);
		free(p);
		FreeTree(p->right);
	}
}
// p->right 전에 p가 참조하는 메모리 영역이 없어지므로 p->right를 참조할 수 없다.
