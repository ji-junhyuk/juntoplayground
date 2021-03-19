#include <stdio.h>
int sum(int n1, int n2)
{
	return n1+n2;
}

void main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	sum(n1, n2);
	printf("%d %d = %d\n", n1, n2, sum(n1, n2));
}
