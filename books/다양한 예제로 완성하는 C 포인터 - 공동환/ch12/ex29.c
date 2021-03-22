#include <stdio.h>
void CallbackClient();

void PrintInt(int data)
{
    printf("%d\n", data);

    CallbackClient();
}

void CallbackClient()
{
	printf("클라이언트 코드\n");           
}

void main()
{
	PrintInt(10);
}
