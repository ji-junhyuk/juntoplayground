#include <stdio.h>
#include <stdlib.h>
#include "pr03.h"

int Initialize(ArrayIntQueue *q, int max)
{
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(ArrayIntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;
	else
	{
		q->que[q->num++] = x;
		return 0;
	}
}

int Deque(ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		int i;
		*x = q->que[0];
		
		i = 0;
		while (i < q->num-1)
		{
			q->que[i] = q->que[i+1];
			i++;
		}
		q->num--;
	}
}

int Peek(const ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[0];
	return 0;
}

void Clear(ArrayIntQueue *q)
{
	q->num = 0;
}

int Capacity(const ArrayIntQueue *q)
{
	return q->max;
}

int Size(const ArrayIntQueue *q)
{
	return q->num;
}

int IsEmpty(const ArrayIntQueue *q)
{
	return q->num <= 0;
}

int IsFull(const ArrayIntQueue *q)
{
	return q->num >= q->max;
}

int Search(const ArrayIntQueue *q, int x)
{
	int i;

	i = 0;
	while (i < q->num)
	{
		if (q->que[i] == x)
			return i;
		i++;
	}
	return -1;
}

void Print(const ArrayIntQueue *q)
{
	int i;

	i = 0;
	while (i < q->num)
	{
		printf("%d ", q->que[i]);
		i++;
	}
	puts("");
}

void Terminate(ArrayIntQueue *q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = 0;
}
