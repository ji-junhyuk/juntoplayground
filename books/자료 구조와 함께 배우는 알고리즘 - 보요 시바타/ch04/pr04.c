int Search2(const IntQueue *q, int x)
{
	int i;

	i = 0;
	while (i < q->num)
	{
		if (q->que[(i + q->front) % q->max] == x)
			return i;
		i++;
	}
	return -1;
}
