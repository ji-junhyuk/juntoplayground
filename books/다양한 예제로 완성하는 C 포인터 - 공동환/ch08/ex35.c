#include <stdio.h>
struct _point
{
	int x;
	int y;
};

void func(struct _point *ps)
{
	printf("%d %d\n", ps->x, ps->y);
}

void main()
{
	struct _point p1 = {5, 5};
	func(&p1);
}
