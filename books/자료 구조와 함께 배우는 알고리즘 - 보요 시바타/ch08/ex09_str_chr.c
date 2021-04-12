#include <stdio.h>

int str_chr(const char *s, int c)
{
	int i = 0;
	c = (char)c;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return -1;
		i++;
	}
	return i;
}

int main()
{
	char str[64];
	char tmp[64];
	int ch;
	int idx;

	scanf("%s", str);

	printf("찾을 문자: ");
	scanf("%s", tmp);
	ch = tmp[0];

	if ((idx = str_chr(str, ch)) == -1)
		printf("문자 %c 없음.\n", ch);
	else
		printf("문자 %c는 %d에 있음.\n", ch, idx + 1);
}
