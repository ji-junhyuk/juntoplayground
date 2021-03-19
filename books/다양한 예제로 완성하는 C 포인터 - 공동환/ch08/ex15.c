#include <stdio.h>
void func3(int n3)
{
	printf("%d\n", n3);
}

void func2(int n2)
{
	func3(n2+1);
}

void func1(int n1)
{
	func2(n1+1);
}

void main()
{
	int m = 10;
	func1(m);
}
