#include <stdio.h>
union _upoint
{
	int x;
	int y;
};

int main()
{
	union _upoint u1;

	u1.x = 10;
	u1.y = 20;

	printf("%d %d\n", u1.x, u1.y);
}
