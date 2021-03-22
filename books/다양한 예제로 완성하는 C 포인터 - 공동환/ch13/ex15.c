#include <stdio.h>
int ustrlen(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;

	return i;
}

void main()
{
	char *str = "ABCDE";

	printf("%d\n", ustrlen(str));
}
