#include <stdio.h>
int main()
{
	int n = 20;
	int *np = &n;
	*np = 30;
	printf("%d %d\n", n, *np);
}
