#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point sarr[5] = {1,2,3,4,5,6,7,8,9,10};

	printf("%d %d\n", sarr[0].x, sarr[0].y);
	printf("%d %d\n", sarr[1].x, sarr[1].y);
	printf("%d %d\n", sarr[2].x, sarr[2].y);
	printf("%d %d\n", sarr[3].x, sarr[3].y);
	printf("%d %d\n", sarr[4].x, sarr[4].y);
}
