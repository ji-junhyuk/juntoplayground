#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point s1 = {1, 1};
	struct _point *sp = &s1;
	struct _point **spp = &sp;

	printf("%d %d\n", s1.x, s1.y);
	printf("%d %d\n", sp->x, sp->y);
	printf("%d %d\n", (*spp)->x, (*spp)->y);
	printf("%d %d\n", (**spp).x, (**spp).y);
}
