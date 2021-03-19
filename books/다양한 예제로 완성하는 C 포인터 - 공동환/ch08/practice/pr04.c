#include <stdio.h>
struct _point 
{
	int x;
	int y;
};

void print1(struct _point s)
{
	printf("%d %d\n", s.x, s.y);
}

void print2(struct _point *ps)
{
	printf("%d %d\n", ps->x, ps->y);
}

void main()
{
	struct _point p1 = {10, 10}, p2 = {20, 20};
	print1(p1);
	print2(&p2);
}
