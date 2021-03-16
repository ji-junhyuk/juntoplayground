#include <stdio.h>
int main()
{
	char c = 'A';

	char (*ap1)[2] = (char (*)[2])&c;
	char (*ap2)[4] = (char (*)[4])&c;
	char (*ap3)[3][3] = (char (*)[3][3])&c;

	printf("%c %c %c\n", **ap1, **ap2, ***ap3);
	printf("%c %c %c\n", ap1[0][0], ap2[0][0], ap3[0][0][0]);

	printf("%p %p %p %p\n", ap1, ap1+1, ap1[0], ap1[1]);
	printf("%p %p %p %p\n", ap2, ap2+1, ap2[0], ap2[1]);
	printf("%p %p %p %p\n", ap3, ap3+1, ap3[0], ap3[0]);
	printf("%p %p %p %p\n", ap3[0], ap3[0]+1, ap3[0][0], ap3[0][1]);
}
