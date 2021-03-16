#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point p1 = {10, 10};

	printf("(%d, %d)\n", p1.x, p1.y);
	printf("(%d, %d)\n", (&p1)->x, (&p1)->y);
	printf("%d %d\n", (*&p1).x, (*&p1).y);
}
