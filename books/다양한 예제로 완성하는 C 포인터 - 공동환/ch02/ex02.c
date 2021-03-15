#include <stdio.h>
int main()
{
	int n = 20;
	int *np = &n;
	printf("%d %d\n", n, *np);
	printf("%ld %ld\n", sizeof(int), sizeof(int *));
	printf("%ld %ld\n", sizeof(n), sizeof(np));
}
