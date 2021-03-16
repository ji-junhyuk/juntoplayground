#include <stdio.h>
int main()
{
	char carr2[2][2] = {'A', 'B', 'C', 'D'};

	printf("%p %p %d\n", carr2, *carr2, **carr2);
	printf("%p %p %d\n", carr2, carr2[0], carr2[0][0]);
}
