#include <stdio.h>
struct _point
{
	int x;
	int y;
};

struct _point func()
{
	struct _point s = {4, 6};
	
	return s;
}

void main()
{
	struct _point p1;

	p1 = func();

	printf("%d %d\n", p1.x, p1.y);
}
