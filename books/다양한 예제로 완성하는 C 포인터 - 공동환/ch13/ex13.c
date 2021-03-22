#include <stdio.h>
void ustrcpy(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] = s2[i])
		i++;
}

void main()
{
	char *str1 = "ABCD";
	char temp[100];

	ustrcpy(temp, str1);

	puts(str1);
	puts(temp);
}
