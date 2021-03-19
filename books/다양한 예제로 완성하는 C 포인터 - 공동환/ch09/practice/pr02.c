#include <stdio.h>
void *func(int num)
{
	static char c = 'A';
	static int n = 50;
	static double d = 5.5;

	switch (num)
	{
		case 1:
			return &c;
		case 2:
			return &n;
		case 3:
			return &d;
	}
	return NULL;
}

void main()
{
	printf("%c\n", *(char *)func(1));
	printf("%d\n", *(int *)func(2));
	printf("%g\n", *(double *)func(3));
}
