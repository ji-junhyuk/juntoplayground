#include <stdio.h>
int main()
{
	int n = 100;
	int (*ap1)[2] = (int (*)[2])&n;
	int (*ap2)[4] = (int (*)[4])&n;
	int (*ap3)[3][3] = (int (*)[3][3])&n;

	printf("%d %d %d\n", **ap1, **ap2, ***ap3);
	printf("%d %d %d\n", ap1[0][0], ap2[0][0], ap3[0][0][0]);

	printf("%p %p %p %p\n", ap1, ap1+1, ap1[0], ap1[1]);
	printf("%p %p %p %p\n", ap2, ap2+1, ap2[0], ap2[1]);
	printf("%p %p %p %p\n", ap3, ap3+1, ap3[0], ap3[1]);
	printf("%p %p %p %p\n", ap3[0], ap3[0]+1, ap3[0][0], ap3[0][1]);
}
