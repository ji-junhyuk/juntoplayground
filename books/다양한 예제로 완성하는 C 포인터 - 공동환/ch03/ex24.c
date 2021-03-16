#include <stdio.h>
int main()
{
	char carr3[2][2][3] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	printf("%p %p %p %d\n", carr3, carr3[0], carr3[0][0], carr3[0][0][0]);
	printf("%p %p %p %d\n", carr3+1, carr3[0]+1, carr3[0][0]+1, carr3[0][0][0]+1);
	printf("%p %p %p %d\n", carr3+1, *carr3+1, **carr3+1, ***carr3+1);
}
