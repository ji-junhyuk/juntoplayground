#include <stdio.h>

int main()
{
	int n = 100;

	printf("%p\n", &n);
	printf("%d %d\n", n, *&n);
}
