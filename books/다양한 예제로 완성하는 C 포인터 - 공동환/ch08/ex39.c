#include <stdio.h>
struct _point
{
	int x;
	int y;
};

struct _point *func()
{
	static struct _point s = {10, 9};

	return &s;
}

void main()
{
	struct _point *ps;
	ps = func();
	printf("%d %d\n", ps->x, ps->y);
}
