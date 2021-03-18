#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point p1 = {10, 20};
	struct _point *ps = &p1;

	printf("%d %d\n", p1.x, p1.y);
	printf("%d %d\n", ps->x, ps->y);
}
