#include <stdio.h>
int functional1()
{
	puts("함수1");
	return 1;
}
int functional2()
{
	puts("함수2");
	return 2;
}
void main()
{
	int (*func)();
	func = functional1;
	printf("%d\n", func());
	func = functional2;
	printf("%d\n", func());
}
