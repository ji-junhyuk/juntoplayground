#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point p1 = {10, 10};

	printf("%p %p %p\n", &p1, &p1.x, &p1.y);
	printf("%p %p %p\n", &p1+1, &p1.x+1, &p1.y+1);
}
