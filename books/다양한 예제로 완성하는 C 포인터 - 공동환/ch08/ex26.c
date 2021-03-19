#include <stdio.h>
void func(char *s)
{
	puts(s);
}

void main()
{
	char *str = "abcd";
	func(str);
}
