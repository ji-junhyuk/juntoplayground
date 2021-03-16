#include <stdio.h>
int main()
{
	char str[] = "ABCDEFG";

	puts(str);
	puts(&str[0]);
	puts(str+1);
	puts(&str[1]);
	puts(str+2);
	puts(&str[2]);
}
