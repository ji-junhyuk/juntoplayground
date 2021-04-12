#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int main()
{
	char *s1 = "ABCD";
	char *s2 = "EFGH";

	swap(char *, s1, s2);

	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}
