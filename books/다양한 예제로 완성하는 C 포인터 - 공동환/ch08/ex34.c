#include <stdio.h>
struct _point
{
	int x;
	int y;
};

void func(struct _point s)
{
	printf("%d %d\n", s.x, s.y);
}

void main()
{
	struct _point p1 = {5, 5};
	func(p1);
}
