#include <stdio.h>
int main()
{
	char c = 'Z';
	char *cp = &c;
	int n = 100;
	int *np = &n;
	printf("%ld %ld %ld\n", sizeof(c), sizeof(*cp), sizeof(cp));
	printf("%ld %ld %ld\n", sizeof(n), sizeof(*np), sizeof(np));
}
