#include <stdio.h>
void move(int no, int x, int y)
{
	if (no > 1)
		move(no-1, x, 6-x-y);
	printf("%d, %d, %d\n", no, x, y);

	if (no > 1)
		move(no-1, 6-x-y, y);
}

int main()
{
	int n;
	move(3, 1, 3);

	return 0;
}
