#include <stdio.h>
int main()
{
	char carr[5] = {'A', 'B', 'C', 'D', 'E'};

	printf("%c %c %c %c %c\n", *&carr[0], *&carr[1], *&carr[2], *&carr[3], *&carr[4]);
}
