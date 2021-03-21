#include <stdio.h>
void main()
{
	char *names[] = {"junhyuk", "junto", "jiguree"};
	printf("%c\n", *(*(names+1)+2));
	printf("%c\n", names[1][3]);
}
