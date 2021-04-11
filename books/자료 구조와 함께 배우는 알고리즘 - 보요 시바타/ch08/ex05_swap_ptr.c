#include <stdio.h>

void swap_ptr (char **x, char **y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	char *s1 = "ABCD";
	char *s2 = "EFGH";

	swap_ptr(&s1, &s2);

	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}
