#include <stdio.h>
int main()
{
	char carr2[2][2] = {'A', 'B', 'C', 'D'};
	printf("%p %p %d\n", carr2+1, *(carr2+1), **(carr2+1));
	printf("%p %p %d\n", carr2+1, carr2[1], carr2[1][0]);
}
