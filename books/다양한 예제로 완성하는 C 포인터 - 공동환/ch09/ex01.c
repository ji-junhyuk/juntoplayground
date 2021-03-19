#include <stdio.h>
void main()
{
	char c = 'A';
	int n = 10;
	void *vp;

	vp = &c;
	printf("%p %p\n", &c, vp);

	vp = &n;
	printf("%p %p\n", &n, vp);
}
