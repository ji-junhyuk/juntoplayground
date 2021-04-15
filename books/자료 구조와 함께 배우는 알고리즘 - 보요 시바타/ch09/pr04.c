void Purge(Dlist *list, int compare(const Member *x, const Member *y))
{
	Dnode *ptr = list->head->next;

	while (ptr != list->head)
	{
		Dnode *ptr2 = ptr;
		Dnode *pre = ptr;

		while (pre->next != list->head)
		{
			ptr2 = pre->next;
			if (!compare(&ptr->data, &ptr2->data))
			{
				pre->next = ptr2->next;
				free(ptr2);
			}
			else
				pre = ptr2;
		}
		ptr = ptr->next
	}
	list->crnt = list->head;
}

Dnode *retrieve(Dlist *list, int n)
{
	Dnode *ptr = list->head->next;

	while (n >= 0 && ptr != list->head)
	{
		if (n-- = 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}
