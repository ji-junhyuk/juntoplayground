#include <stdio.h>
#include <string.h>
void main()
{
	int n1 = 0x2010, n2 = 0x40302010;
	int i;

	i = 0;
	while (i < 4)
	{
		if (memcmp((char *)&n1+i, (char *)&n2+i, 1) == 0)
			puts("T");
		else
			puts("F");
		i++;
	}
}
