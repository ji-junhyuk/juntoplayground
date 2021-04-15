void Purge(List *list, int compare(const Member *x, const Member *y))
{
	Node *ptr = list->head;

	while (ptr != NULL)
	{
		Node *ptr2 = ptr;
		Node *pre = ptr;

		while (pre->next != NULL)
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
		ptr = ptr->next;
	}
	list->crnt = list->head;
}
