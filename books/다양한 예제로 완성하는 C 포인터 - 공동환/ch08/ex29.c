#include <stdio.h>
void Print()
{
	printf("Print integer: ");
}

int *func()
{
	int n;
	scanf("%d", &n);

	return &n;
}

void main()
{
	int *ip;

	ip = func();
	Print();
	printf("%d\n", *ip);
}

//컴파일 에러
