#include <stdio.h>
#define STACKSIZE 10
#define ERROR_VALUE 0xfffffff

void Push(int Stack[], int *top, int data)
{
	if (*top == STACKSIZE)
	{
		puts("더이상 자료를 저장할 수 없습니다.");
		return ;
	}
	Stack[(*top)++] = data;
}

int Pop(int Stack[], int *top)
{
	if (*top == 0)
	{
		puts("자료가 없습니다.");
		return ERROR_VALUE;
	}
	return Stack[--*top];
}

void main()
{
	int Stack[STACKSIZE];
	int top = 0;

	Push(Stack, &top, 100);
	Push(Stack, &top, 100);
	Push(Stack, &top, 100);

	printf("%d\n", Pop(Stack, &top));
	printf("%d\n", Pop(Stack, &top));
	printf("%d\n", Pop(Stack, &top));
}
