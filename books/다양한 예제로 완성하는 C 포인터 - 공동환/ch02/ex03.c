#include <stdio.h>
int main()
{
	char c = 'A';
	char *cp = &c;
	*cp = 66;
	printf("%c %c\n",c , *cp);
}
