#include <stdio.h>
int main()
{
	int a = 10, b = 20, c = 30, d = 40, e = 50;
	int *iarr[5] = {&a, &b, &c, &d, &e};
	
	printf("%p %p %p %p %p\n", &a, &b, &c, &d, &e);
	printf("%p %p %p %p %p\n", iarr[0], iarr[1], iarr[2], iarr[3], iarr[4]);

	printf("%d %d %d %d %d\n", a, b, c, d, e);
	printf("%d %d %d %d %d\n", *iarr[0], *iarr[1], *iarr[2], *iarr[3], *iarr[4]);
}
