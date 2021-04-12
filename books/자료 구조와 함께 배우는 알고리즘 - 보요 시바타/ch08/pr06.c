#include <stdio.h>

char *str_rchr(const char *s, int c)
{
	const char *p = NULL;

	c = (char)c;
	while (1)
	{
		if (*s == c)
			p = s;
		if (*s == '\0')
			break;
		s++;
	}
	return (char *)p;
}

int main()
{
	char str[64];
	char tmp[64];
	int ch;
	char *idx;

	scanf("%s", str);

	printf("찾을 문자: ");
	scanf("%s", tmp);
	ch = tmp[0];

	if ((idx = str_rchr(str, ch)) == NULL)
		printf("문자 %c 없음.\n", ch);
	else
		printf("문자 %c는 %ld에 있음.\n", ch, (idx - str));

	return 0;
}
