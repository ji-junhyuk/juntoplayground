#include <stdio.h>
void main()
{
	int n = 10;
	int *np;
	void *vp;

	vp = &n;
	printf("%d %d\n", n, *(int *)vp);

	np = (int *)vp;
	printf("%d %d\n", n, *np);
}
