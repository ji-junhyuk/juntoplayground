#include <stdio.h>
void b()
{
	printf("b() \n");
}

void a()
{
	b();
	printf("a() \n");
}

void main()
{
	a();
	printf("main() \n");
}
