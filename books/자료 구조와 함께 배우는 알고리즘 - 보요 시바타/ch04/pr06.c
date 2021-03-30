#include <stdio.h>
#include <stdlib.h>
#include "pr06.h"

int Initialize(IntDequeue *q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int EnqueFront(IntDequeue *q, int x)
{
	if (q->num >= q-> max)
		return -1;
	else
	{
		q->num++;
		if (--q->front < 0)
			q->front = q->max - 1;
		q->que[q->front] = x;
		return 0;
	}
}

int EnqueRear(IntDequeue *q, int x)
{
	if (q->num >= q->max)
		return -1;
	else
	{
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

int DequeFront(IntDequeue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int DequeRear(IntDequeue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		if (--q->rear < 0)
			q->rear = q->max-1;
		*x = q->que[q->rear];
		return 0;
	}
}

int PeekFront(const IntDequeue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

//Deque rear한 값이 나오는거 같은데..
int PeekRear(const IntDequeue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->rear];
	return 0;
}

void Clear(IntDequeue *q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntDequeue *q)
{
	return q->max;
}

int Size(const IntDequeue *q)
{
	return q->num;
}

int IsEmpty(const IntDequeue *q)
{
	return q->num <= 0;
}

int IsFull(const IntDequeue *q)
{
	return q->num >= q->max;
}

int Search(const IntDequeue *q, int x)
{
	int i, idx;

	i = 0;
	while (i < q->num)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
		i++;
	}
	return -1;
}

int Search2(const IntDequeue *q, int x)
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

void Print(const IntDequeue *q)
{
	int i;

	i = 0;
	while (i < q->num)
	{
		printf("%d ", q->que[(i + q->front) % q->max]);
		i++;
	}
	puts("");
}

void Terminate(IntDequeue *q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}
