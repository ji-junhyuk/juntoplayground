#include <stdio.h>
#include <string.h>
void main()
{
	int n1;
	int n2 = 20;

	memcpy(&n1, &n2, sizeof(int));
	printf("%d %d\n", n1, n2);
}
