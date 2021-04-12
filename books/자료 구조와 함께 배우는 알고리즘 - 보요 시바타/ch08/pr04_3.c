#include <stdio.h>

size_t str_len(const char *s)
{
	const char *p = s;
	while (*s)
		s++;
	return s - p;
}

int main()
{
	char str[256];
	printf("문자열: ");
	scanf("%s", str);
	printf("길이: %ld\n", str_len(str));

	return 0;
}
