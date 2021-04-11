#include <stdio.h>

size_t str_len(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return len;
}

int main()
{
	char str[256];
	printf("문자열: ");

	scanf("%s", str);
	printf("길이: %ld\n", str_len(str));

	return 0;
}
