#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point sarr[2][2] = {{{1,2}, {3,4}}, {{5,6}, {7,8}}};

	printf("%p %p %p\n", sarr, sarr[0], sarr[1]);
	printf("%p %p %p\n", sarr+1, sarr[0]+1, sarr[1]+1);

	printf("%d %d %d %d\n", sarr[0][0].x, sarr[0][0].y, sarr[0][1].x, sarr[0][1].y);
	printf("%d %d %d %d\n", sarr[0][2].x, sarr[0][2].y, sarr[0][3].x, sarr[0][3].y);
	printf("%d %d %d %d\n", sarr[1][-2].x, sarr[1][-2].y, sarr[1][-1].x, sarr[1][-1].y);
	printf("%d %d %d %d\n", sarr[1][0].x, sarr[1][0].y, sarr[1][1].x, sarr[1][1].y);
}
