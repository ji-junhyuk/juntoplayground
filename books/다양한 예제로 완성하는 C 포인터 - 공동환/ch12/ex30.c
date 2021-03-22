#include <stdio.h>
void CallbackClient();

void PrintInt(int data, void (*pf)())
{
	printf("%d", data);
	pf();
}

void Callback1()
{
	printf("클라이언트 코드!");
}

void Callback2()
{
	printf("===========");
}

void Callback3()
{
	printf("*************");
}

void main()
{
	PrintInt(10, Callback1);
	PrintInt(10, Callback2);
	PrintInt(10, Callback3);
}
