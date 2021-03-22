#include <stdio.h>
void ustrcat(char *s1, char *s2)
{
	int i, j;
	
	i = 0;
	while (s1[i])
		i++;

	j = 0;
	while (s1[i] = s2[j])
	{
		i++;
		j++;
	}
}

void main()
{
	char *str1 = "ABCD";
	char temp[100] = "123";

	ustrcat(temp, str1);

	puts(str1);
	puts(temp);
}
