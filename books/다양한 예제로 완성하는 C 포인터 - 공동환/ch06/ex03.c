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

	p1.x = 20;
	p1.y = 20;

	printf("(%d, %d)\n", p1.x, p1.y);
}
