#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point sarr[2][2] = {{{0, 1}, {2,3}}, {{4,5}, {6,7}}};
	
	printf("%d %d %d %d\n", sarr[0][0].x, sarr[0][0].y, sarr[0][1].x, sarr[0][1].y);
	printf("%d %d %d %d\n", sarr[1][0].x, sarr[1][0].y, sarr[1][1].x, sarr[1][1].y);

	sarr[0][0].x = 10, sarr[0][0].y = 9;
	sarr[0][1].x = 8, sarr[0][1].y = 7;
	sarr[1][0].x = 6, sarr[1][0].y = 5;
	sarr[1][1].x = 4, sarr[1][1].y = 3;
	printf("%d %d %d %d\n", sarr[0][0].x, sarr[0][0].y, sarr[0][1].x, sarr[0][1].y);
	printf("%d %d %d %d\n", sarr[1][0].x, sarr[1][0].y, sarr[1][1].x, sarr[1][1].y);
}
