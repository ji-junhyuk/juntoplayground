#include <stdio.h>
void main()
{
	void (*fp)();

	fp = main;
	printf("%p %p\n", main, fp);
}
