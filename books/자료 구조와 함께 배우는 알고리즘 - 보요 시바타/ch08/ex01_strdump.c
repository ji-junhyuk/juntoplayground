#include <stdio.h>
#include <limits.h>

void str_dump(const char *s)
{
	do {
		int i;
		puts("");
		printf("*s >> 1");
		putchar((*s >> 1) & 1U);
		puts("");
		printf("%c %0*X ", *s, 2, *s);
		for (i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((*s >> i) & 1U) ? '1' : '0');
		putchar('\n');
	} while (*s++ != '\0');
}

int main()
{
	str_dump("STRING");
	return 0;
}
