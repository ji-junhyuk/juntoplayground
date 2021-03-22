#include <stdio.h>
#include <string.h>
void main()
{
	char *str1 = "ABCDEFGHI";
	char *str2 = "AB12EFG3I";
	int i;

	i = 0;
	while (i < 10)
	{
		if (memcmp(str1+i, str2+i, 2) == 0)
			puts("T");
		else
			puts("F");
		i+=2;
	}
}
