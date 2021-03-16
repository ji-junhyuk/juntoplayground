#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	int n1 = 10;
	struct _point p1 = {10, 10};

	printf("%ld %ld\n", sizeof(n1), sizeof(p1));
	printf("%ld %ld\n", sizeof(p1.x), sizeof(p1.y));
}
