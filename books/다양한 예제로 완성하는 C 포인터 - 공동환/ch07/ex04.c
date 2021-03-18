#include <stdio.h>
struct _point 
{
	int x;
	int y;
};

int main()
{
	struct _point sarr[5] = {1,2,3,4,5,6,7,8,9,10};
	struct _point *sp = sarr;

	printf("%d %d\n", sp[0].x, sp[0].y);
	printf("%d %d\n", sp[1].x, sp[1].y);
	printf("%d %d\n", sp[2].x, sp[2].y);
	printf("%d %d\n", sp[3].x, sp[3].y);
	printf("%d %d\n", sp[4].x, sp[4].y);
	printf("%d %d\n", sp->x, sp->y);
	printf("%d %d\n", (sp+1)->x, (sp+1)->y);
	printf("%d %d\n", (sp+2)->x, (sp+2)->y);
	printf("%d %d\n", (sp+3)->x, (sp+3)->y);
	printf("%d %d\n", (sp+4)->x, (sp+4)->y);
}
