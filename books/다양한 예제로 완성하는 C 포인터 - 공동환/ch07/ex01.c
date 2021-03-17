#include <stdio.h>
struct _point 
{
	int x;
	int y;
};

int main()
{
	struct _point s1 = {10, 10};
	struct _point *sp = &s1;
	
	printf("%d %d\n", s1.x, s1.y);
	printf("%d %d\n", sp->x, sp->y);
	printf("%d %d\n", (*sp).x, (*sp).y);
}
