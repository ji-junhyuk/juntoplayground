#include <stdio.h>
#define QUEUESIZE 10
#define ERROR_VALUE 0xfffffff

void Add(int Queue[], int *front, int *rear, int data)
{
	if ((*rear + 1) % QUEUESIZE == *front)
	{
		puts("더이상 자료를 저장할 수 없습니다.");
		return ;
	}
	Queue[*rear = (*rear + 1) % QUEUESIZE] = data;
}

int Delete(int Queue[], int *front, int *rear)
{
	if (*front == *rear)
	{
		puts("자료가 없습니다.");
		return ERROR_VALUE;
	}
	return Queue[*front = (*front+1) % QUEUESIZE];
}

void main()
{
	int Queue[QUEUESIZE];
	int front = 0, rear = 0;

	Add(Queue, &front, &rear, 10);
	Add(Queue, &front, &rear, 20);
	Add(Queue, &front, &rear, 30);

	printf("%d\n", Delete(Queue, &front, &rear));
	printf("%d\n", Delete(Queue, &front, &rear));
	printf("%d\n", Delete(Queue, &front, &rear));
}
