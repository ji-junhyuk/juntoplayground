#include <stdio.h>
void func()
{
	int an = 0;
	static int sn = 0;
	printf("%d %d\n", ++an, ++sn);
}

void main()
{
	func();
	func();
	func();
}
