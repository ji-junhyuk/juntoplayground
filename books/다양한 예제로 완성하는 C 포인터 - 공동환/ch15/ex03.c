#include <stdio.h>
typedef int STACKDATA;
#define STACKSIZE 10
#define ERROR_VALUE (STACKDATA)0xfffffff
void Push(STACKDATA Stack[], int *top, STACKDATA data)
{
	if (*top == STACKSIZE)
	{
		puts("더이상 자료를 저장할 수 없습니다.");
		return ;
	}
	Stack[(*top)++] = data;
}

STACKDATA Pop(STACKDATA Stack[], int *top)
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
	STACKDATA Stack[STACKSIZE];
	int top = 0;

	Push(Stack, &top, 100);
	Push(Stack, &top, 200);
	Push(Stack, &top, 300);

	printf("%d\n", Pop(Stack, &top));
	printf("%d\n", Pop(Stack, &top));
	printf("%d\n", Pop(Stack, &top));
}
