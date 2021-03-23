#include <stdio.h>
#define STACKSIZE 10
#define ERROR_VALUE 0xfffffff
int Stack[STACKSIZE];
int top = 0;
void Push(int data)
{
	if (top == STACKSIZE)
	{
		puts("더 이상 자료를 저장할 수 없습니다.");
		return ;
	}
	Stack[top++] = data;
}

int Pop()
{
	if (top == 0)
	{
		puts("자료가 없습니다.");
		return ERROR_VALUE;
	}
	return Stack[--top];
}

void main()
{
	Push(100);
	Push(200);
	Push(300);

	printf("%d\n", Pop());
	printf("%d\n", Pop());
	printf("%d\n", Pop());
	printf("%d\n", Pop());
}
