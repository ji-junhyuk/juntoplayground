#include <stdio.h>
#include <string.h>
void main()
{
	char *str = "ABCDE";

	printf("%ld\n", strlen(str+2));
}
