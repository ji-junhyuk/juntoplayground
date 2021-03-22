#include <stdio.h>
#include <string.h>
void main()
{
	int n1 = 10, n2 = 10;

	if (memcmp(&n1, &n2, sizeof(int)) == 0)
		puts("T");
	else
		puts("F");
} 
