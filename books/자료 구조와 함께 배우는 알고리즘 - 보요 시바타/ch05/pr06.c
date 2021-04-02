#include <stdio.h>
void move(int no, int x, int y)
{
	char *name[] = {"A기둥", "B기둥", "C기둥"};
	if (no > 1)
		move(no-1, x, 6-x-y);
	printf("%d, %s, %s\n", no, name[x-1], name[y-1]);

	if (no > 1)
		move(no-1, 6-x-y, y);
}

int main()
{
	int n;
	move(3, 1, 3);

	return 0;
}
