#include <stdio.h>
struct _point
{
	int x;
	int y;
};

int main()
{
	struct _point s1 = {1, 2};
	struct _point *sp = &s1;
	struct _point **spp = &sp;

	printf("%ld %ld %ld\n", sizeof(s1), sizeof(sp), sizeof(spp));
	printf("%p %p %p %p\n", &s1, sp, spp, &spp);
	printf("%p %p %p %p\n", &s1+1, sp+1, spp+1, &spp+1);
}
