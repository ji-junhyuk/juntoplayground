#include <stdio.h>
#include <string.h>
void main()
{
	int n = 0x44434241;
	char c;
	int i;

	i = 0;
	while (i < 4)
	{
		memcpy(&c, (char *)&n+i, sizeof(char));
		printf("%c %x\n", c, c);
		i++;
	}
}
