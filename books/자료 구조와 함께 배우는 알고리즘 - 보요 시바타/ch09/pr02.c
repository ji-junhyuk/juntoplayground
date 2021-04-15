Node *Retrieve(List *list, int n)
{
	Node *ptr = list->head;

	while (n >= 0 && ptr != NULL)
	{
		if (n-- == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}
