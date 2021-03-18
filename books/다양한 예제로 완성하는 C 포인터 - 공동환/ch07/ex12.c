#include <stdio.h>
struct _aData
{
	char *pcarr;
	int *piarr;
};

int main()
{
	char carr[4] = {'A', 'B', 'C', 'D'};
	int iarr[4] = {10, 20, 30, 40};
	struct _aData s1 = {carr, iarr};

	printf("%c %c %c %c\n", carr[0], carr[1], carr[2], carr[3]);
	printf("%c %c %c %c\n", s1.pcarr[0], s1.pcarr[1], s1.pcarr[2], s1.pcarr[3]);

	printf("%d %d %d %d\n", iarr[0], iarr[1], iarr[2], iarr[3]);
	printf("%d %d %d %d\n", s1.piarr[0], s1.piarr[1], s1.piarr[2], s1.piarr[3]);
}
