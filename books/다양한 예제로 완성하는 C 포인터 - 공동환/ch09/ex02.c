#include <stdio.h>
void main()
{
	char c = 'A';
	int n = 10;
	void *vp;

	vp = &c;
	printf("%c %c\n", c, *(char *)vp);

	vp = &n;
	printf("%d %d\n", n, *(int *)vp);
}
