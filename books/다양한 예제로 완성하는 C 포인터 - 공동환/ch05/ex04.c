#include <stdio.h>
int main()
{
	char *cp = "ABCD";
	char carr[10] = "ABCD";

	printf("%c %c\n", cp[0], carr[0]);
//	cp[0] = 'Z';
	carr[0] = 'Z';
	cp = carr;
//	carr = cp;

	printf("%c %c\n", cp[0], carr[0]);
}
