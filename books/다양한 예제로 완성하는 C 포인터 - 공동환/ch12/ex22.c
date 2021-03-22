#include <stdio.h>
void main()
{
	char carr[2][3] = {{'A','B','C'}, {'1','2','3'}};
	printf("%p %p %p\n", carr, carr[0], &carr[0][0]);
	printf("%p %p %p\n", carr+1, carr[0]+1, &carr[0][0]+1);
}
