#include <stdio.h>
char * getstr()
{
	static int i = 1;
	static char str[100];
	sprintf(str, "함수호출 : %d", i++);
	return str;
}


void main()
{
	puts(getstr());
	puts(getstr());
	puts(getstr());
}
