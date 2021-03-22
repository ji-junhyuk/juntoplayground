#include <stdio.h>

int ustrcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return 1;
		else if (s1[i] < s2[i])
			return -1;
		i++;
	}
	return 0;
}

void main()
{
	char *str1 = "ABCD";
	char *str2 = "ABCD";

	printf("%d\n", ustrcmp(str1, str2));
	if (ustrcmp(str1, str2) == 0)
		puts("T");
	else
		puts("F");
}
