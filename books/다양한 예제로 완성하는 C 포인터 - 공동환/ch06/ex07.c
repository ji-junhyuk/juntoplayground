#include <stdio.h>
struct _point
{
	double x;
	double y;
};

int main()
{
	struct _point p1 = {10, 10};

	printf("%ld %ld %ld\n", sizeof(p1), sizeof(p1.x), sizeof(p1.y));
}
