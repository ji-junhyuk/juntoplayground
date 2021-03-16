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

	printf("%ld\n", sizeof(union _upoint));
	printf("%p\n", &u1);
	printf("%p %p %p\n", &u1, &u1.x, &u1.y);
	printf("%p %p %p\n", &u1+1, &u1.x+1, &u1.y+1);
}
