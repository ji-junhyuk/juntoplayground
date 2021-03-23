#include <stdio.h>
#define QUEUESIZE 10
#define ERROR_VALUE 0xfffffff

int Queue[QUEUESIZE];
int front = 0, rear = 0;

void Add(int data)
{
	if (rear == QUEUESIZE)
	{
		puts("더이상 자료를 저장할 수 없습니다.");
		return ;
	}
	Queue[rear++] = data;
}

int Delete()
{
	if (front == QUEUESIZE)
	{
		puts("자료가 없습니다.");
		return ERROR_VALUE;
	}
	return Queue[front++];
}

void main()
{
	Add(10);
	Add(20);
	Add(30);

	printf("%d\n", Delete());
	printf("%d\n", Delete());
	printf("%d\n", Delete());
}
