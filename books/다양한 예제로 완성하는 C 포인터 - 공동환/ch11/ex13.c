#include <stdio.h>
#include <stdlib.h>
void main()
{
	char c1, c2;
	char temp1[20] = "a A";
	char temp2[20];

	sscanf(temp1, "%c %c", &c1, &c2);
	printf("%c %c\n", c1, c2);

	sprintf(temp2, "%c %c", c1, c2);
	printf("%s\n", temp2);
}
