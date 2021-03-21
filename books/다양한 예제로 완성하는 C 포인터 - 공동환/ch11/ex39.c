#include <stdio.h>
void main()
{
	int n1 = 0, n2 = 0;

	if(n1++ || n2++)
		puts("TRUE");
	else 
		puts("FALSE");
	printf("%d %d\n", n1, n2);
}
