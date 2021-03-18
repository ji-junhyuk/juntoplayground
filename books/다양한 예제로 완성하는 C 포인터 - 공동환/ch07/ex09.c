#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point sarr[2][2] = {{{0,1}, {2,3}}, {{4,5}, {6,7}}};
	struct _point (*ap)[2] = (struct _point (*)[2])sarr;

	printf("%p %p %p\n", ap, ap[0], ap[1]);
	printf("%p %p %p\n", ap+1, ap[0]+1, ap[1]+1);

	printf("%d %d %d %d\n", ap[0][0].x, ap[0][0].y, ap[0][1].x, ap[0][1].y);
	printf("%d %d %d %d\n", ap[1][0].x, ap[1][0].y, ap[1][1].x, ap[1][1].y);
}
