#include <stdio.h>
void func(char ap[])
{
	printf("%c %c %c %c\n", ap[0], ap[1], ap[2], ap[3]);
}

void main()
{
	char carr[4] = {'A', 'B', 'C', 'D'};
	func(carr);
}
