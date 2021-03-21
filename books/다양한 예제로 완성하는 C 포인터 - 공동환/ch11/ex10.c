#include <stdio.h>
void main()
{
	char temp[20];

	fgets(temp, 20, stdin);
	fputs(temp, stdout);
}
