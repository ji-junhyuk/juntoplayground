#include <stdio.h>
void main()
{
	int n1 = 1, n2 = 0;

	if (n1++ || n2++)
		puts("참");
	else
		puts("거짓");
	printf("%d %d\n", n1, n2);
}
